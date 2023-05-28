#include <iostream>
#include <cmath>

using namespace std;

void solve(){
  int x,k; cin >> x >> k;
  if(x % k == 0){
    cout << 2 << endl;
    cout << x-1 << " " << 1 << endl;
  }

  else{
    cout << 1 << endl;
    cout << x << endl;
  }
}

int main(){

  int t;cin >> t;

  for(int i = 0; i < t; i++){
    solve();
  }

}
