#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void solve(){
  int n; cin >> n;

  char curr_char; cin >> curr_char;
  bool flag = false;


  for(int i = 1; i < n; i++){
    char c; cin >> c;
    if (flag){
      curr_char = c;
      flag = false;
    }
    else if (c==curr_char){
      cout << curr_char;
      flag = true;
    }

  }

  cout << endl;

}


int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
