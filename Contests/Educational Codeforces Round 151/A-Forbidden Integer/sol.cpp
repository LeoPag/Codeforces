#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve(){

 int n;
 int k;
 int x;
 cin >> n >> k >> x;
 if(x != 1){
   cout << "YES" << endl;
   cout << n << endl;
   for(int i = 0; i < n; i++){
     cout << 1 << " ";
   }
   cout << endl;
   return;
 }
 if(x == 1){
   if(k == 1){
     cout << "NO" << endl;
     return;
   }
   if(k == 2){
     if(n%2 == 0){
       cout << "YES" << endl;
       cout << n/2 << endl;
       for(int i = 0; i < n/2; i++){
         cout << 2 << " ";
       }
       cout << endl;
       return;
     }
     else{
       cout << "NO" << endl;
       return;
     }
   }
   if(k >= 3){
     if(n%2 == 0){
       cout << "YES" << endl;
       cout << n/2 << endl;
       for(int i = 0; i < n/2; i++){
         cout << 2 << " ";
       }
       cout << endl;
       return;
     }
     if(n%2 == 1){
       cout << "YES" << endl;
       cout << (n-1)/2 << endl;
       for(int i = 0; i < ((n-1)/2)-1; i++){
         cout << 2 << " ";
       }
       cout << 3 << endl;
       return;
     }
   }
 }

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
