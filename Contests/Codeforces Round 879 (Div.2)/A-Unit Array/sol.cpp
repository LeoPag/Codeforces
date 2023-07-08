#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve(){

 int n; cin >> n;

 int count_plus = 0;
 int count_minus = 0;

 for (int i = 0; i < n; i++){
   int ai; cin >> ai;
   if(ai == 1){
     count_plus ++;
   }
   else{
     count_minus ++;
   }
 }

 if(count_plus >= count_minus){
   if(count_minus%2 == 1){
     cout << 1 << endl;
   }
   else{
     cout << 0 << endl;
   }
 }
 else{
   int extra_plus = (n/2) + n%2 - count_plus;
   if((n - count_plus - extra_plus) % 2 == 1) cout << extra_plus + 1 << endl;
   else cout << extra_plus<< endl;

 }
}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
