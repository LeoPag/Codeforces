#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(){
  string s; cin >> s;
  string t; char last = '0';
  for(int i = 0; i < s.size(); i++){
    if (s[i] != '?'){
      t.push_back(s[i]);
      last = s[i];
    }
    else {
      t.push_back(last);
    }
  }
  cout << t << endl;
}

int main(){

  int t;cin >> t;

  for(int i = 0; i < t; i++){
    solve();
  }
}
