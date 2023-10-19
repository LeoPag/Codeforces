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


int start_cycle;
typedef queue<int> QI;


void dfs(int start_node, int parent, VVI& adj_list, VI& visited, VI& distances, int curr_distance){
    if(visited[start_node] == 1){
        if(start_cycle == -1) start_cycle = start_node;
        return;
    }
    distances[start_node] = curr_distance;
    visited[start_node] = 1;
    for(auto it = adj_list[start_node].begin(); it != adj_list[start_node].end(); it++){
        int neighbour = *it;
        if(neighbour != parent) dfs(neighbour,start_node, adj_list,visited,distances,curr_distance+1);
    }
}


int bfs(int start_node, int target, VVI adj_list, int n){
    QI q;
    q.push(start_node);
    VI visited(n+1,0);
    VI distances(n+1,0);

    visited[start_node] = 1;
    
    while(q.empty() == false){
        int curr_node = q.front();
        q.pop();
        if(curr_node == target) return distances[target];
        for(auto it = adj_list[curr_node].begin(); it != adj_list[curr_node].end(); it++){
            int neighbour = *it;
            if(visited[neighbour] == 1) continue;
            visited[neighbour] = 1;
            q.push(neighbour);
            distances[neighbour] = distances[curr_node] + 1;
        }
    }

    return 0;

}

// SOLVE
void solve(){

    int n,a,b; cin >> n >> a >> b;

    start_cycle = -1;

    VVI adj_list(n+1);

    f(0,i,n){
        int from,to; cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    VI visited(n+1,0);
    VI distances_b(n+1,-1);

    dfs(b,-1,adj_list,visited,distances_b,0);

    int distance_a = bfs(a,start_cycle,adj_list,n);

    
    if(distances_b[start_cycle] < distance_a) print("YES");
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
        //if(it == 2) return 0;
    }
    return 0;
}