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
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef pair<double,double> PD;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<vector<ll> > VVL;
typedef vector<vector<PL> > VVPL;
typedef vector<PL> VPL;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sort(v) sort(v.begin(),v.end())
#define f(start,i,end) for(int i = start; i < end; i++)
#define f_rev(start,i,end) for(int i = start; i > end; i--)
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
#define print(var) cout << var << endl
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl
#define print_pair(p) cout << p.first << " " << p.second << endl
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

typedef map<long,int> MLI;
typedef std::priority_queue<long> max_heap; // Default behaviour
typedef std::priority_queue<long, std::vector<long>, std::greater<long> > min_heap;

// SOLVE
void solve(){

    int q; cin >> q;
    MLI lefts;
    MLI rights;

    max_heap qmax;
    min_heap qmin;

    f(1,i,q+1){

        char c; cin >> c;
        ll l,r; cin >> l >> r;

        if(c == '+'){
            lefts[l] += 1;
            rights[r] += 1;
            qmax.push(l);
            qmin.push(r);
        }
        if(c == '-'){
            lefts[l] -= 1;
            rights[r] -= 1;
        }
        while(lefts[qmax.top()] == 0) {
            qmax.pop();
            if(qmax.empty() == true) break;
        }
        while(rights[qmin.top()] == 0) {
            qmin.pop();
            if(qmin.empty() == true) break;
        }
        if((qmax.empty() == true) or (qmin.empty() == true)) print("NO");
        else if(qmax.top() > qmin.top()) print("YES");
        else print("NO");
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}