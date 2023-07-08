#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int


void solve(){

 int n; cin >> n;

 string s1,s2;

 for(int i = 0; i < n; i++){
   char c; cin >> c;
   s1.push_back(c);
 }

 for(int i = 0; i < n; i++){
   char c; cin >> c;
   s2.push_back(c);
 }

 int front_distance = 0;

 for(int i = 0; i < n; i++){
   if(s1[i] != s2[i]) front_distance ++;
 }

 int reverse_distance = 0;

 for(int i = 0; i < n; i++){
   if(s1[i] != s2[n-1-i]) reverse_distance ++;
 }


int front_moves = max(0,2*front_distance - front_distance%2);
int reverse_moves = max(2,2*(reverse_distance) - (1 - reverse_distance%2));

cout << min(front_moves,reverse_moves) << endl;

}



int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
