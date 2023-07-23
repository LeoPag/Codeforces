#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef pair<double,double> PD;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<ll> > VVL;
typedef vector<vector<PL> > VVPL;
typedef vector<PL> VPL;
typedef vector<PI> VPI;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++)
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max(v) *max_element(v.begin(), v.end())
#define print(var) cout << var << endl
// MODULAR DIVISION
ll get_pow_mod(ll n, ll x){
    ll ret = 1;
    while(x){
      if(x&1)
       (ret*=n)%=MOD;
      x>>=1;
      (n*=n)%=MOD;
     }
     return ret;
}
ll get_mod_inverse(ll b){
    return get_pow_mod(b,MOD-2);
}
ll modDivide(ll a, ll b){
    ll inverse = get_mod_inverse(b);
    return a % MOD * inverse % MOD;
}


ll compute_fib(ll k){
    if(k == 1) return 0;
    if(k == 2) return 1;

    ll prec1 = 0;
    ll prec2 = 1;
    ll fib = 0;

    f(0,i,k-2){
        fib = prec1 + prec2;
        prec1 = prec2;
        prec2 = fib;
    } 
    return fib;
}



// SOLVE
void solve(){

    int n; cin >> n;
    ll k; cin >> k;

    if(k > n+10){
        if(n == 0) print(1);
        else print(0);
        return;
    }

    ll kth_fact = compute_fib(k);
    ll kth_fact_prev = compute_fib(k-1);

    //cout << kth_fact_prev << " " << kth_fact << endl;

    //return;

    ll res = 0;

    f(0,a,n/2 + 10){

        if(n - kth_fact_prev*a < 0) break;

        ll b = (n - kth_fact_prev*a) / kth_fact;
        ll rem = (n - kth_fact_prev*a) % kth_fact;

        //cout << a << " "<< b <<" "<< rem << endl;

        if((b >= a) & (rem == 0)){
            res += 1;
        }
    }

    print(res);

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
    }
    return 0;
}