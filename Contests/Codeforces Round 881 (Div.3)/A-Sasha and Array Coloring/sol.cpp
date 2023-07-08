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
  VI arr;
  for(int i  = 0; i < n; i++){
    int ai; cin >> ai;
    arr.push_back(ai);
  }

  sort(arr.begin(), arr.end());
  int max_score = 0;
  for(int i = 0; i < n/2; i++){
    max_score += arr[n-1-i] - arr[i];
  }
  cout << max_score << endl;

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
