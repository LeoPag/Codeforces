#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll calc(ll w, ll k){

  if(w == 0){
    return 0;
  }
  if(k > w){
    return 0;
  }
  ll res = w - k + 1;
  k++;
  while(k!=w+1){
    res += (w - k + 1);
    k++;
  }
  return res;
}

void solve(){

  ll n; cin >> n;
  ll k; cin >> k;
  ll q; cin >> q;

  ll count = 0;

  ll res = 0;
  ll temp = 0;


  while (n--){
    ll day; cin >> day;

    if (day <= q){
      temp += 1;
    }
    else{
      res += calc(temp,k);
      temp = 0;
    }
  }

  res += calc(temp,k);

 cout << res << endl;


}


int main(){

  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
