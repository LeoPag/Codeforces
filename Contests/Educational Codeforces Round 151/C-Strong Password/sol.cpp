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
typedef vector<VI> VVI;

void solve(){

  cin >> s >> m >> l >> r;

  int n = int(s.size());

  VVI nxt(n+1,VI(10,n+1));

  for(int i = n-1; i >= 0; i--){
    for(int c = 0; c < 10; c++){
      nxt[i][c] = nxt[i+1][c];
    }
    nxt[i][s[i]-'0'] = i+1;
  }

  int p = 0;

  for(int j = 0; j < m; j++){
    int q = -1;
    for(int k = l[j]; k <= r[j]; k++){
      q = max(q,nxt[p][k -'0']);
    }
    p = q;
    if(p == n+1){
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
