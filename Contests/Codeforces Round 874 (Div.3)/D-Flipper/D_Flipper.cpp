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
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++) 
  
void solve(){
    
    int n; cin >> n;

    VI nums(n);
    int pos = -1;
    int pos_second = -1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] == n) pos = i;
        if(nums[i] == n-1) pos_second = i;
    }

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    if(pos == n-1){
        cout << n << " ";
        int idx = pos - 1;
        while(nums[0]<nums[idx]){
            cout << nums[idx] << " ";
            idx -= 1;
        }
        int point = 0;
        while(point <= idx){
            cout << nums[point] << " ";
            point += 1;
        }
        cout << endl;
        return;
    }

    if(pos > 0){
        for(int idx = pos; idx < n; idx++) cout << nums[idx] << " ";
        cout << nums[pos - 1] << " ";
        int idx = pos - 2;
        if(idx < 0){
            cout << endl;
            return;
        }
        while(nums[0] < nums[idx]){
            cout << nums[idx] << " ";
            idx -= 1;
        }
        int point = 0;
        while(point <= idx){
            cout << nums[point] << " ";
            point += 1;
        }
        cout << endl;
        return;
    }


    if(pos == 0){
        if(pos_second == n-1){
            cout << n-1 << " ";
            for(int i = 0; i < n-1; i++) cout << nums[i] << " ";
            cout << endl;
            return;
        }
        for(int idx = pos_second; idx < n; idx++) cout << nums[idx] << " ";
        cout << nums[pos_second - 1] << " ";
        for(int idx = 0; idx < pos_second-1; idx++) cout << nums[idx] << " ";
        cout << endl;
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