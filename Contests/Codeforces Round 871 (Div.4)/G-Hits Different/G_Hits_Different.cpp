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
#include <bitset>

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

const int M = 2023;

ll ans;
VI visited;


ll sum_squared(ll n){
    return n*(n+1)*(2*n+1) / 6;
}

void explore(int row_idx, ll min_int, ll max_int){

    ll gauss_min = (row_idx * (row_idx - 1) / 2) + 1;
    ll gauss_max = gauss_min + row_idx - 1;

    ans += (sum_squared(max_int) -  sum_squared(min_int-1));

    if(row_idx == 1) return;

    ll new_min = min_int - row_idx;
    if(min_int == gauss_min) new_min += 1;

    ll new_max = max_int - row_idx + 1;
    if(max_int == gauss_max) new_max -= 1;

    explore(row_idx - 1, new_min, new_max); 
}


// SOLVE
void solve(){
    
    ans = 0;
    ll n; cin >> n;

    if(n == 1){
        print(1);
        return;
    }

    ll c = 1;
    ll d = 1;


    visited = VI(n+1,0);

    int row_idx = -1;

    f(1,i,M+1){
        c+=i;
        d+=i+1;
        if(n <= d) {
            row_idx = i+1;
            break;
        }
    }

    explore(row_idx,n,n);

    print(ans);

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
        //if(it == 2) return 0;
    }
    return 0;
}
