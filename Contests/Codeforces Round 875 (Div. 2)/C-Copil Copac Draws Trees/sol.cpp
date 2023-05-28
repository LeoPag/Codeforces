#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;

int max_read;
VI visited;
VPI drawn_at_read;

//DFS
void dfs(const VVPI& adj_list, int curr_node){

    visited[curr_node] = 1;
    for(auto p = adj_list[curr_node].begin(); p != adj_list[curr_node].end(); p++){

        if (visited[(p->first)]== 0){
          if(p->second < drawn_at_read[curr_node].second){
            drawn_at_read[p->first] = make_pair(drawn_at_read[curr_node].first + 1,p->second);
          }
        else{
          drawn_at_read[p->first] = make_pair(drawn_at_read[curr_node].first ,p->second);
        }

        max_read = max(max_read, drawn_at_read[p->first].first);
        dfs(adj_list, p->first);
      }

    }
}

void solve(){

  int n; cin >> n;

  max_read = 0;
  visited = VI(n+1,0);
  // 1-based-idx
  // drawn at read[i] contains the turn at which node i was drawn along with the order on the list
  drawn_at_read = VPI(n+1,make_pair(0,0));
  drawn_at_read[1] = make_pair(1,-1);

  // Build adjacency list
  VVPI adj_list(n+1);
  for(int i = 0; i < n-1;i++){
    int from, to; cin >> from >> to;
    adj_list[from].push_back(make_pair(to,i));
    adj_list[to].push_back(make_pair(from,i));
  }

  dfs(adj_list, 1);
  cout << max_read << endl;

}


int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
