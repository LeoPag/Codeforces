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

// SOLVE
void solve(){

    int n; cin >> n;

    VVI ans(2,VI(n,0));

    ans[0][0] = 2*n;
    ans[1][n-1] = 2*n - 1;

    int c = n;
    int left_idx = 0;
    int right_idx = n-2;
    int flag = 1;

    while (c != 0){
        if(flag == 1){
            ans[1][left_idx] = c;
            left_idx += 2;
        }
        else{
            ans[1][right_idx] = c;
            right_idx -= 2;
        }
        c-=2;
        flag *= -1;
    }
    left_idx = 1;
    right_idx = n-1;
    flag = 1;
    c = n-1;
    while (c != -1){
        if(flag == 1){
            ans[0][left_idx] = c;
            left_idx += 2;
        }
        else{
            ans[0][right_idx] = c;
            right_idx -= 2;
        }

        c-=2;
        flag *= -1;
    }



    left_idx = 1;
    right_idx = n-3;
    flag = 1;
    c = n+2;
 
    while(c != 2*n){
        if(flag == 1){
            ans[1][left_idx] = c;
            left_idx += 2;
        }
        else{
            ans[1][right_idx] = c;
            right_idx -= 2;
        }
        c+=2;
        flag *= -1;
    }

    left_idx = 2;
    right_idx = n-2;
    flag = 1;
    c = n+1;
 
    while(c != 2*n-1){
        if(flag == 1){
            ans[0][left_idx] = c;
            left_idx += 2;
        }
        else{
            ans[0][right_idx] = c;
            right_idx -= 2;
        }
        c+=2;
        flag *= -1;
    }



    f(0,i,2){
        print_vec(ans[i]);
    }


   



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
