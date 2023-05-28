#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(){
  int consecutive = 1;
  int max_consecutive = 1;
  int n; cin >> n;
  char last_sign; cin >> last_sign;
  for(int i =  1; i < n; i++){
    char curr_sign; cin >> curr_sign;
    if(curr_sign == last_sign){
      consecutive++;
      max_consecutive = max(max_consecutive, consecutive);
    }
    else{
      consecutive = 1;
    }
    last_sign = curr_sign;
  }
  cout << max_consecutive + 1 << endl;

}

int main(){
  
  int t;cin >> t;

  for(int i = 0; i < t; i++){
    solve();
  }
}
