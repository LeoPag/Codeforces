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
    int n,m,h; cin >> n>>m >> h;
    int pos = 1;
    int Rud_score = 0;
    int Rud_pen = 0;
    for(int i = 0; i < n; i++){
        VI problems(m);
        for(int j = 0; j < m; j++)cin >> problems[j];

        sort(problems.begin(), problems.end());
        if(i == 0){
            int time = 0;
            for (int j = 0; j < m; j++){
                if(time+problems[j] <= h){
                    Rud_score += 1;
                    time += problems[j];
                    Rud_pen += time;
                }
            else break;
            }
        }
        else{
            int time = 0;
            int pen = 0;
            int solved = 0;
            for (int j = 0; j < m; j++){
                if(time+problems[j] <= h){
                    solved += 1;
                    time += problems[j];
                    pen += time;
                }
                else break;
            }
            if(solved > Rud_score) pos += 1;
            else if((solved == Rud_score) & (pen < Rud_pen)) pos += 1;
        }    
    }
    cout << pos << endl;

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