#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

typedef vector<int> VI;
void solve(){

  int n; cin >> n;

  VI frequencies(100,0);

  for(int i = 0; i < n; i++){
    int li; cin >> li;
    frequencies[li] ++;
  }

  for(int i = 1; i < 100; i++){
    if(frequencies[i] > frequencies[i-1]){
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
 
}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
