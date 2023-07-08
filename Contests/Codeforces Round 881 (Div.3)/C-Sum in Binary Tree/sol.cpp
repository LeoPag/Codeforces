#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

typedef vector<int> VI;

void solve(){

  ll n; cin >> n;
  ll s = 0;
  while(n != 1){
    s += n;
    if(n%2 == 1){
      n = (n-1)/2;
    }
    else{
      n = n/2;
    }
  }
  cout << s + 1 << endl;

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
