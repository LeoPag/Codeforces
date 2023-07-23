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

bool is_pos;


void dfs(int node, VL& coords, VI& explored, VVPL& adj_list, ll new_coord){
    if(explored[node] == 1){
        if(coords[node] != new_coord) is_pos = false;
        return;
    }
    explored[node] = 1;
    coords[node] = new_coord;
    for(auto it = adj_list[node].begin(); it != adj_list[node].end(); it++){
        int next_node = it->first;
        ll next_coord = new_coord + it->second;
        dfs(next_node, coords, explored, adj_list, next_coord);
    }
}



// SOLVE
void solve(){

    is_pos = true;
    int n,m; cin >> n >> m;
    VVPL adj_list(n+1);
    f(0,i,m){
        int ai,bi; cin >> ai >> bi;
        ll di; cin >> di;
        adj_list[ai].push_back(make_pair(bi,-di));
        adj_list[bi].push_back(make_pair(ai,di));
    }

    VL coords(n+1,0);
    VI explored(n+1,0);

    f(1,i,n+1){
        if(explored[i] == 0) dfs(i,coords,explored, adj_list, 0);
    }

    if(is_pos) print("YES");
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
    }
    return 0;
}