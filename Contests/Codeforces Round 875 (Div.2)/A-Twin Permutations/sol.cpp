#include <iostream>
#include <cmath>

using namespace std;

void solve(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    cout << n + 1 - a << " ";
  }
  cout << endl;
}

int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
