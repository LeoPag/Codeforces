#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;

void solve(){

  int n; cin >> n;
  VI permutations;

  int index_max = 0;
  int index_2 = 0;
  int index_1 = 0;
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    permutations.push_back(p);
    if(permutations[i] == n){
      index_max = i;
    }
    if (permutations[i] == 2){
      index_2 = i;
    }
    if (permutations[i] == 1){
      index_1 = i;
    }
  }

  if ((index_1 < index_max) && (index_2 < index_max)){
      if(index_1 > index_2){
          cout << index_1 + 1 << " " << index_max + 1 << endl;
      }
      else{
          cout << index_2 + 1 << " " << index_max + 1 << endl;
      }
    }

else if ((index_1 > index_max) && (index_2 > index_max)){
    if(index_1 > index_2){
          cout << index_2 + 1 << " " << index_max + 1 << endl;
      }
      else{
          cout << index_1 + 1 << " " << index_max + 1 << endl;
      }
}
else{
    cout << 1 << " " << 1 << endl;
}
  }

int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
