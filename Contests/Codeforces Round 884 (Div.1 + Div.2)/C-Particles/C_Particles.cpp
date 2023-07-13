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

    VL particles(n);
    ll res = -1000000000;

    bool is_pos = false;
    for(int i = 0; i < n;i++){
        cin >> particles[i];
        res = max(res, particles[i]);
        if(particles[i] > 0) is_pos = true;
    } 

    if (is_pos){

        ll odd = 0;
        for(int i = 0; i < n; i+=2){
            if(particles[i] > 0) odd += particles[i];
        }
        res = max(res, odd);
        ll even = 0;
        for(int i = 1; i < n; i+=2){
            if(particles[i] > 0) even += particles[i];
        }
        res = max(res, even);
    }
    
    cout << res << endl;

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