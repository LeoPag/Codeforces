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
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
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

// SOLVE
void solve(){

    int n; cin >> n;
    VL a(n-1);
    f(0,i,n-1) cin >> a[i];

    VI differences(n+1,0);

    ll big_diff = -1;
    if(a[0] <= n) differences[a[0]] = 1;
    else big_diff = a[0];

    f(1,i,n-1){
        ll diff = a[i] - a[i-1];
        if(diff > n){
            if(big_diff == -1) big_diff = diff;
            else{
                print("NO");
                return;
            }
        }

        else if (differences[diff] == 1){
            if(big_diff == -1) big_diff = diff;
            else{
                print("NO");
                return;
            }
        }
        else differences[diff] = 1;
    }

    if(big_diff == -1){
      print("YES");
      return;
    }
  
    int count = 0;

    f(1,j,n+1){
        if(differences[j] == 0) big_diff -= j;
    }
 
    if(big_diff == 0) print("YES");
    else print("NO");

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
        //if(it == 9) return 0;
    }
    return 0;
}