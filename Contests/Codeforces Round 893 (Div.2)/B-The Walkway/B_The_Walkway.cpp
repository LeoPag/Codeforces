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
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl
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
 
// SOLVE
void solve(){
 
   ll n,m,d; cin >> n >> m >> d;
   VL s(m);
   f(0,i,m) cin >> s[i];
   
   ll c = 1;
   ll extra = 0;
   if(s[0] > 1) {
       c+= 1;
        extra = (s[0] - 2) / d;
   }
   c += extra;
 
   f(1,i,m){
       c += 1;
       extra = (s[i] - 1 - s[i-1]) / d;
       c += extra;
   }
   
   extra = (n-s[m-1]) / d;
   c += extra;
   
   ll res_min = c;
   ll count_min = 0;
   
 
    f(0,missing,m){
        ll part = c;
        if(missing == 0){
 
            if(m == 1){
                if(s[missing] != 1) part = c - 1 + (n-1)/d - (n - s[missing])/ d - (s[missing]-2)/d;
      
            }
            else{
                if(s[missing] != 1) part = c - 1 + (s[missing+1]-2)/d - (s[missing+1] -1 - s[missing]) / d - (s[missing]-2)/d;
            }
 
        }
        
        else if(missing == m-1){
            part = c - 1 + (n-s[missing-1]) / d - (n-s[missing]) / d - (s[missing] - 1 -s[missing-1]) / d;
       
        }
        
        else{
            part = c - 1 + (s[missing+1] -1 - s[missing-1])/d - (s[missing + 1] - 1 - s[missing]) / d -(s[missing] - 1 - s[missing-1]) / d  ;
        }
        
        if(part < res_min){
            res_min = part;
            count_min = 1;
        }
        else if (part == res_min) count_min += 1;
    }
    
    cout << res_min << " " << count_min << endl;
    
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