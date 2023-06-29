#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve(){

 ll xa,ya,xb,yb,xc,yc;
 cin >> xa >> ya >> xb >> yb >> xc >>yc;

 ll horizontal_b = xb - xa;
 ll vertical_b = yb - ya;
 ll horizontal_c = xc - xa;
 ll vertical_c = yc - ya;

 ll ans = 0;
 if(horizontal_b * horizontal_c > 0){
   ans += min(abs(horizontal_b),abs(horizontal_c));
 }
 if(vertical_b * vertical_c > 0){
   ans += min(abs(vertical_b),abs(vertical_c));
 }
 cout << ans + 1 << endl;

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
