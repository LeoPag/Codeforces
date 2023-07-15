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
ll MOD = pow(10,9) + 7;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++)

// MODULAR DIVISION
ll get_pow_mod(ll n, ll x){
    ll ret = 1;
    while(x){
      if(x&1)
       (ret*=n)%=MOD;
      x>>=1;
      (n*=n)%=MOD;
     }
     return ret;
}
ll get_mod_inverse(ll b){
    return get_pow_mod(b,MOD-2);
}
ll modDivide(ll a, ll b){
    ll inverse = get_mod_inverse(b);
    return a % MOD * inverse % MOD;
}


// SOLVE
void solve(){
    int n,m; cin >> n >> m;
    VL levels(n);
    f(0,i,n) cin >> levels[i];
    sort(levels);

    unordered_map<ll,int> freq;

    int start = 0;
    int end = 0;
    int unique = 0;
    ll valid_combinations = 1;
    ll tot = 0;


    while(end < n){
        valid_combinations = valid_combinations % MOD;

        if(freq[levels[end]] == 0) unique += 1;
        freq[levels[end]] += 1;
        if(freq[levels[end]] > 1) valid_combinations = modDivide((valid_combinations % MOD) * (freq[levels[end]]),(freq[levels[end]] - 1));


        while (levels[end] - levels[start] >= m){
            if(freq[levels[start]] == 1) unique -= 1;
            if(freq[levels[start]] > 1) valid_combinations = modDivide((valid_combinations % MOD) * (freq[levels[start]]-1), (freq[levels[start]]));
            freq[levels[start]]--;
            start += 1;
        }


        if(unique == m) {
            ll extra = modDivide(valid_combinations, freq[levels[end]]);
            tot += extra;
            tot = tot % MOD;
        }
        end += 1;
    }

    cout << tot % MOD << endl;

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
