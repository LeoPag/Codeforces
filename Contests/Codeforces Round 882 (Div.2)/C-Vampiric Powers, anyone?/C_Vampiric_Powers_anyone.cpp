#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef pair<double,double> PD;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<ll> > VVL;
typedef vector<vector<PL> > VVPL;
typedef vector<PL> VPL;
typedef vector<PI> VPI;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
  
void solve(){

    int n; cin >> n;
    VI arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    VI cum(n+1,0);
    for(int i = 1; i < n+1; i++) cum[i] = cum[i-1]^ arr[i-1];

  
    int res = 0;

    for(int c = 255; c >= 0; c--){
        VI visited(256,0);
        for(int i = 0; i < n+1; i++){
            if(visited[c^cum[i]]){
                cout << c << endl;
                return;
            }
            visited[cum[i]] = 1;
        }
    }

}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}