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

// C++ function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1){
       cout << "Division not defined";
       return -1;
    }
    else return  (inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}


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
        if(freq[levels[end]] > 1) valid_combinations = modDivide((valid_combinations % MOD) * (freq[levels[end]]),(freq[levels[end]] - 1),MOD);

        //cout << "ANALYS: " << end << " " << valid_combinations << endl;
        
        while (levels[end] - levels[start] >= m){
            //cout << "In" << endl;
            if(freq[levels[start]] == 1) unique -= 1;
            if(freq[levels[start]] > 1) valid_combinations = modDivide((valid_combinations % MOD) * (freq[levels[start]]-1), (freq[levels[start]]), MOD);
            freq[levels[start]]--;
            start += 1;
        }

        //cout << start << " "<< end <<" "<< unique << endl;

        if(unique == m) {
            ll extra = modDivide(valid_combinations, freq[levels[end]], MOD);
            tot += extra;
            tot = tot % MOD;
            //cout << "END: " << start << " " << end << " " << extra << " " << tot << endl;
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
        //cout << "TESTCASE: " << it << endl;
        solve();
    }
    return 0;
}