#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll count_score(string s){
    char max_c = 'A';
    int n = s.size();
    ll score = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] >= max_c){
            max_c = s[i];
            score += pow(10,s[i]-'A');
        }
        else{
            score -= pow(10,s[i]-'A');
        }
    }

    return score;
}

void solve(){

  string s; cin >> s;
  ll max_score = count_score(s);
  int n = s.size();

  //Found first position of every letter from the left

  int loca = -1;
  int locb = -1;
  int locc = -1;
  int locd = -1;
  int loce = -1;

  for(int i = 0; i < n; i++){
      if((s[i] == 'A') && (loca == -1)){
          loca = i;
      }
      if((s[i] == 'B') && (locb == -1)){
          locb = i;
      }
      if((s[i] == 'C') && (locc == -1)){
          locc = i;
      }
      if((s[i] == 'D') && (locd == -1)){
          locd = i;
      }
      if((s[i] == 'E') && (loce == -1)){
          loce = i;
      }
  }

  //Change loca
  if (loca != -1){
      s[loca] = 'B';
      max_score = max(max_score, count_score(s));
      s[loca] = 'C';
      max_score = max(max_score, count_score(s));
      s[loca] = 'D';
      max_score = max(max_score, count_score(s));
      s[loca] = 'E';
      max_score = max(max_score, count_score(s));
      s[loca] = 'A';
  }


  //Change locb
  if (locb != -1){
      s[locb] = 'C';
      max_score = max(max_score, count_score(s));
      s[locb] = 'D';
      max_score = max(max_score, count_score(s));
      s[locb] = 'E';
      max_score = max(max_score, count_score(s));
      s[locb] = 'B';
  }

  //Change locc
  if (locc != -1){
      s[locc] = 'D';
      max_score = max(max_score, count_score(s));
      s[locc] = 'E';
      max_score = max(max_score, count_score(s));
      s[locc] = 'C';
  }

  //Change locd
  if (locd != -1){
      s[locd] = 'E';
      max_score = max(max_score, count_score(s));
      s[locd] = 'D';
  }

  //Found position of every letter from the right
  loca = -1;
  locb = -1;
  locc = -1;
  locd = -1;
  loce = -1;

  for(int i = n-1; i >= 0; i--){
      if((s[i] == 'A') && (loca == -1)){
          loca = i;
      }
      if((s[i] == 'B') && (locb == -1)){
          locb = i;
      }
      if((s[i] == 'C') && (locc == -1)){
          locc = i;
      }
      if((s[i] == 'D') && (locd == -1)){
          locd = i;
      }
      if((s[i] == 'E') && (loce == -1)){
          loce = i;
      }
  }

  //Change loce
  if (loce != -1){
      s[loce] = 'A';
      max_score = max(max_score, count_score(s));
      s[loce] = 'B';
      max_score = max(max_score, count_score(s));
      s[loce] = 'C';
      max_score = max(max_score, count_score(s));
      s[loce] = 'D';
      max_score = max(max_score, count_score(s));
      s[loce] = 'E';
  }

  //Change locd
  if(locd != -1){
      s[locd] = 'A';
      max_score = max(max_score, count_score(s));
      s[locd] = 'B';
      max_score = max(max_score, count_score(s));
      s[locd] = 'C';
      max_score = max(max_score, count_score(s));
      s[locd] = 'D';
  }


  //Change locc
  if(locc != -1){
      s[locc] = 'A';
      max_score = max(max_score, count_score(s));
      s[locc] = 'B';
      max_score = max(max_score, count_score(s));
      s[locc] = 'C';
  }


  //Change locb
  if(locb != -1){
      s[locb] = 'A';
      max_score = max(max_score, count_score(s));
      s[locb] = 'B';
  }

  cout << max_score << endl;
}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
