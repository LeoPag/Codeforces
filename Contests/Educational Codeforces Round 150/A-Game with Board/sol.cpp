#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve(){

 int n; cin >> n;
 if(n == 1)cout << "Alice" << endl;
 else if(n <= 4)cout << "Bob" << endl;
 else cout << "Alice"<< endl;

}


int main(){
  int t;cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
