#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

#define ll long long int

typedef vector<ll> VL;
typedef vector<VL> VVL;

VL sinks;
VVL adjacency_list;

void dfs(int root, int parent){
    int children = adjacency_list[root].size();
    bool is_leaf = true;
    for(int child_idx = 0; child_idx < children; child_idx++){
        int child = adjacency_list[root][child_idx];

        if(child != parent){
            is_leaf = false;
            dfs(child, root);
            sinks[root] += sinks[child];
        }
    }
    if(is_leaf){
        sinks[root] += 1;
    }
}

void solve(){

  int n; cin >> n;

  adjacency_list = VVL(n+1);
  sinks = VL(n+1,0);

  for(int i = 0; i < n-1; i++){
    int from, to; cin >> from >> to;
    adjacency_list[from].push_back(to);
    adjacency_list[to].push_back(from);
  }

  dfs(1,-1);


  int q; cin >> q;
  for(int i = 0; i < q; i++){
      int x,y; cin >> x >> y;

        cout << (sinks[x] * sinks[y]) << endl;

  }

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
