#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

typedef vector<ll> VL;
void solve(){

  int n; cin >> n;
  VL arr;
  ll sum_tot = 0;
  for(int i  = 0; i < n; i++){
    ll ai; cin >> ai;
    sum_tot += abs(ai);
    arr.push_back(ai);
  }
  ll count_pos = 0;
  ll count_neg = 0;

  bool start = false;

  for(int i = 0; i < n; i++){
    if(arr[i] < 0){
      start = true;
    }
    else if(arr[i] > 0) {
      if(start == true) count_neg++;
      start = false;
    }
  }
  if(start == true) count_neg++;
  start = false;


  for(int i = 0; i < n; i++){
    if(arr[i] > 0){
      start = true;
    }
    else if(arr[i] < 0) {
      if(start == true) count_pos++;
      start = false;
    }
  }

  if(start == true) count_pos++;

  cout << sum_tot << " " << min(count_neg, count_pos+1) << endl;

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
