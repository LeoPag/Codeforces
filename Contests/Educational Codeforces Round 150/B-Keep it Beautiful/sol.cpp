#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve(){

 int q; cin >> q;

 ll q_1; cin >> q_1;
 cout << 1;

 ll q_last = q_1;
 bool flag = false;
 ll q_shift = 0;

 for (int i = 1; i < q; i++){
   ll q_i; cin >> q_i;

   if (flag == false){
     if(q_i >= q_last){
       q_last = q_i;
       cout << 1;
     }
     else if(q_i <= q_1){
       cout << 1;
       flag = true;
       q_shift = q_i;
       q_last = q_shift;
     }
     else{
       cout << 0;
     }
   }

   else{
     if((q_i >= q_last) and (q_i <= q_1)){
       cout << 1;
       q_last = q_i;
     }
     else{
        cout << 0;
     }
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
