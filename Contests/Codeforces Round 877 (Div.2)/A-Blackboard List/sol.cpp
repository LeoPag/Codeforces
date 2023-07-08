#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(){

  int n; cin >> n;
  int maxim = 0;
  int res = 0;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    maxim = max(maxim,a);
    if (a < 0){
      res = a;
    }
  }
  if (res < 0){
    cout << res;
  }
  else{
    cout << maxim;
  }
  cout << endl;
}

int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
