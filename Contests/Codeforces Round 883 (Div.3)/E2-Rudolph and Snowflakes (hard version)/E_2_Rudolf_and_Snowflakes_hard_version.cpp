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
    ll n;
    cin>>n;
	ll flag=0;
	for(ll level=3;level<=60;level++){
		ll l=2;
		ll r=pow(n,1.0/(level-1))+2;
		while(l<=r){
			ll mid=(l+r)/2;
			ll c=0,pw=1;
			for(int i=0;i<level;i++){
				c+=pw;
				if(c>n) break;
				pw*=mid;
			}
			if(c==n){
				flag=1;
				break;
			}
			if(c>n) r=mid-1;
			else l=mid+1;
		}
		if(flag)
			break;
	}
	cout << ((flag ? "YES" : "NO"))<< endl;
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