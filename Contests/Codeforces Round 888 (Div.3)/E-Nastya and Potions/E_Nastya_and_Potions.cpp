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
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
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

VL coins;
VL ans;
VI unlimited;

ll dfs(int node, VVI& neighs){

    if(ans[node] != -1) return ans[node];
    if(unlimited[node] == 1) {
        ans[node] = 0;
        return 0;
    }
    if(neighs[node].size() == 0){
        ans[node] = coins[node];
        return ans[node];
    }

    ll sum  = 0;

    for(int neigh = 0; neigh < neighs[node].size(); neigh++){
        sum += dfs(neighs[node][neigh], neighs);
    }

    ans[node] = min(coins[node],sum);

    return ans[node];

}


// SOLVE
void solve(){

    int n,k; cin >> n >> k;
    coins = VL(n+1,0);
    ans = VL(n+1,-1);
    f(1,i,n+1) cin >> coins[i];

    unlimited = VI(n+1,0);
    f(0,i,k){
        int idx; cin>>idx;
        unlimited[idx] = 1;
    }

    VVI neighs(n+1);
    
    f(1,i,n+1){
        int m; cin >> m;
        f(0,j,m){
            int pot; cin >> pot;
            neighs[i].push_back(pot);
        }
    }
    f(1,i,n+1){
        dfs(i,neighs);
    }
    f(1,i,n+1){
        cout << ans[i] << " ";
    }
    cout << endl;
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