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
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<vector<ll> > VVL;
typedef vector<vector<PL> > VVPL;
typedef vector<PL> VPL;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++)
#define f_rev(start,i,end) for(int i = start; i > end; i--)
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
#define print(var) cout << var << endl
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
#define print_pair(p) cout << p.first << " " << p.second << endl
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


VI a;
VI cols;
int n;
// SOLVE

void propagate(int start, int power){
    if(start == 0) return;
    if(start == n+1) return;
    if(cols[start] == 1) return;
    cols[start] = 1;
    if(power == 0) return;
    if(power == 2){
        a[start] -= 2;
        propagate(start-1, a[start-1]);
        propagate(start+1, a[start+1]);
    }

    if(power == 1){
        a[start] -= 1;
        if(cols[start-1] == 0)propagate(start-1, a[start-1]);
        else propagate(start+1, a[start+1]);
    }
    
}
void solve(){

    cin >> n;
    a = VI(n+2,0);
    cols = VI(n+2,0);

    f(1,i,n+1) cin >> a[i];
    cols[0] = 1;
    cols[n+1] = 1;

    int ans = 0;

    f(1,i,n+1){
        if(a[i] == 2){
            if(cols[i] == 0) ans += 1;
            propagate(i,2);
        }
    }
    f(1,i,n+1){

        if(a[i] == 1){
            if((cols[i+1] == 1) or (a[i+1] == 0)){
                ans += 1;
                propagate(i,1);
            }
        }
    }
    f(1,i,n+1){
        if(cols[i] == 0) ans += 1;
    }
    print(ans);
}
int main()
{
    fast_cin();

    solve();

    /*
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
        //if(it == 2) return 0;
    }*/

    return 0;
}