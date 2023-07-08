#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


typedef vector<int> VI;


void solve(){
  int n; cin >> n;
  int k; cin >> k;

  if(log2(n) < k) cout << n+1 << endl;
  else cout << (int)pow(2,k) << endl;

}


int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
