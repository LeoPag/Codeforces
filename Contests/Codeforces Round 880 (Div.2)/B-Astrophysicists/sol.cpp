#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

typedef vector<int> VI;
void solve(){


  ll n,k,g; cin >> n >> k >> g;
  ll THR = g/2 + g%2 - 1;
  ll remain = k*g - (n-1)*THR;
  ll r_last = remain % g;
  ll paid = 0;
  if(r_last >= THR + 1){
      paid = remain + (g-r_last);
  }
  else{
      paid = remain - r_last;
  }

  ll res = min(k*g,k*g - paid);

  if(res < 0){
      cout << 0 << endl;
  }
  else{
      cout << res << endl;
  }

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
