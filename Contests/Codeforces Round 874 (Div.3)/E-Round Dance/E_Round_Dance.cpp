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

//Depth First Search finds max_connected_components
int dfs(int node, VI& visited, VVI& adj_matrix, int alone){

    int new_alone = alone;
    if((adj_matrix[node].size() == 1) or (adj_matrix[node][0] == adj_matrix[node][1]) )new_alone += 1;
    visited[node] = 1;

    f(0,i,adj_matrix[node].size()){

        if(visited[adj_matrix[node][i]] == 0){
            new_alone = dfs(adj_matrix[node][i], visited, adj_matrix, new_alone); 
        } 

    }
    return new_alone;
}

void solve(){
    int n; cin >> n;
    VVI adj_matrix(n+1);

    f(1,i,n+1){
        int neigh; cin >> neigh;
        adj_matrix[i].push_back(neigh);
        adj_matrix[neigh].push_back(i);
    }
    
    VI visited(n+1,0);

    int count_max_components = 0;

    int count_min_components = 0;

    int total_alone = 0;
    


    f(1,i,n+1){
        if(visited[i] == 0){ 
            int alone =  dfs(i, visited, adj_matrix,0);
            count_max_components += 1;
            //cout << "COMP: " << count_max_components  << " has " << alone << " single nodes" << endl;
            if(alone == 0) count_min_components += 1;
            else{
                if(total_alone > 0){
                    total_alone = total_alone + alone - 2;
                }
                else{
                    count_min_components += 1;
                    total_alone += alone;
                }
            }

        }
    }



    cout << count_min_components << " " << count_max_components << endl;



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