#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

string s,l,r;
int m;

typedef vector<int> VI;

VI explored;

bool compare(int m_idx, int number, int s_idx){

  if(explored[m-m_idx] >= s_idx){
    return true;
  }

  if(s_idx >= s.size()){
    return false;
  }

  for(int i = s_idx; i < s.size(); i++){
    if(s[i] == number){
      if(m_idx == m-1){
        explored[0] = i;
        return true;
      }
      bool might_be = true;
      for(int j = l[m_idx+1]; j <= r[m_idx+1]; j++){
        might_be = might_be && compare(m_idx + 1, j,i+1);
        if (might_be == false) return false;
      }
      explored[m - (m_idx+1)] = i+1;
      return might_be;
    }
  }
  return false;
}



void solve(){

  cin >> s >> m >> l >> r;

  explored = VI(m+1,-1);

  bool is_not_possible = true;

  for(int k = l[0]; k <= r[0]; k++){
    is_not_possible = is_not_possible && (compare(0,k,0));
    if (is_not_possible == false) break;
  }

  if(is_not_possible){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
  }
}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
