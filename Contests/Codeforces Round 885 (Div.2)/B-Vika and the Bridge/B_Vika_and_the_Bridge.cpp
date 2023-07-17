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

   int n,k; cin >> n >> k;

   VVI steps(k+1);

   f(1,i,n+1){

        int ci; cin >> ci;
        steps[ci].push_back(i);
   }

   f(1,i,k+1){
    steps[i].push_back(n+1);
   }

   int res = 10000000;

   f(1,i,k+1){
    
      int max1 = steps[i][0] - 1;
      int max2 = -1;
      f(1,j,steps[i].size()){
        if(steps[i][j] - steps[i][j-1] - 1 >= max1){
            max2 = max1;
            max1 = steps[i][j] - steps[i][j-1] - 1;
        }

        else if((max2 == -1) or (steps[i][j] - steps[i][j-1] - 1 > max2)){
            max2 = steps[i][j] - steps[i][j-1] - 1;
        }
      }
      int max_step = max((max1 / 2), max2);
      res = min(res,max_step);
   }

   cout << res << endl;

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
