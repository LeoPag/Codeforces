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
ll MOD = pow(10,9) + 7;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++)



bool is_poss;
map<PI,int> m;
VI sols;


int dfs(int start_node, int parent, VVI& adj_list){

    int subtree_size = 1;

    for(int j = 0; j < adj_list[start_node].size(); j++){
        if(adj_list[start_node][j] != parent){
            subtree_size += dfs(adj_list[start_node][j],start_node, adj_list);
        }
    }

    if(subtree_size == 3) {
        sols.push_back(m[make_pair(parent, start_node)]);
        subtree_size = 0;
    }
    if(subtree_size > 3) is_poss = false;
    return subtree_size;
}


void solve(){
    int n; cin >> n;
    
    VVI adj_list(n+1);
    m.clear();
    sols.clear();

    f(1,i,n){
        int from, to; cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
        m[make_pair(from,to)] = i;
        m[make_pair(to, from)] = i;
    }

    if(n%3 != 0){
        cout << -1 << endl;
        return;
    }
        
    is_poss = true;

    dfs(1,-1,adj_list);

    if(is_poss == false){
        cout << -1 << endl;
        return;
    }

    cout << n/3 - 1 << endl;
    f(0,i,sols.size()){
        if(sols[i] != 0) cout << sols[i] << " ";
    } 
    cout << endl;

    
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}