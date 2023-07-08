#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef vector<int>VI;
typedef map<int,int> MI;

void solve(){
  int n; cin >> n;
  MI occ1;
  MI occ2;

  //Init all Hasmaps with zeros;
  for(int i = 1; i <= 2*n; i++){
    occ1[i] = 0;
    occ2[i] = 0;
  }

  //Count consecutives
  int count = 0;
  int last_int = -1;
  for(int i = 0; i < n; i++){
    int a_i; cin >> a_i;
    if(a_i == last_int){
      count++;
    }
    else{
      count = 1;
    }
    occ1[a_i] = max(occ1[a_i], count);
    last_int = a_i;
  }
  count = 0;
  last_int = -1;
  for(int i = 0; i < n; i++){
    int b_i; cin >> b_i;
    if(b_i == last_int){
      count++;
    }
    else{
      count = 1;
    }
    occ2[b_i] = max(occ2[b_i], count);
    last_int = b_i;
  }

  //Find Max length;
  int max_l = 0;

  for (auto it = occ1.begin(); it != occ1.end(); it++){
    max_l = max(max_l, it->second + occ2[it->first]);
  }

  cout << max_l << endl;
}

int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
