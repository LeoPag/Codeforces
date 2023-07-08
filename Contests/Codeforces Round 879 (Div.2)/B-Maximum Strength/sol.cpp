#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int


void solve(){

 string s1,s2; cin >> s1 >> s2;

 if(s1 == s2){
     cout << 0 << endl;
     return;
 }

while(s1.size() < s2.size()){
    s1 = '0' + s1;
}

int n = s1.size();
int score = 0;
bool found = false;
for(int i  = 0; i < n; i++){
    if ((found == false) and (s1[i] != s2[i])){
        found = true;
        score += s2[i] - s1[i];
    }
    else if(found == true){
        score += 9;
    }
}
cout << score << endl;
}



int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
