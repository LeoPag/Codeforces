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
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
#define print(var) cout << var << endl
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
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

typedef map<int,int> MINT;

// SOLVE
void solve(){

    string s,t;
    cin >> s >> t;

    int q,timeout; cin >>timeout>>q;

    int n = s.size();

    MINT m;
    int count_equal  = 0;

    f(0,i,n){
        if(s[i] == t[i]) count_equal += 1;
    }

    int to_comp  = n;

    f(1,i,q+1){
        int mark;
        cin >> mark;

        if(m[i-timeout] > 0){
            to_comp += 1;
            int pos = m[i-timeout] - 1;
            if(s[pos] == t[pos]) count_equal += 1;
        }


        if(mark == 1){
            to_comp -= 1;
            int pos; cin >> pos;
            m[i] = pos;
            if(s[pos-1] == t[pos-1]){
                count_equal -= 1;
            }
        }

        else if(mark == 2){
            int s1,s2,p1,p2; cin >> s1 >> p1 >> s2 >> p2;

            p1 -= 1;
            p2 -= 1;

            if((s1 == 1) & (s2 == 1)){
                if(s[p1] == t[p1]) count_equal -= 1;
                if(s[p2] == t[p1]) count_equal += 1;
                if(s[p2] == t[p2]) count_equal -= 1;
                if(s[p1] == t[p2]) count_equal += 1;
                swap(s[p1],s[p2]);
            }
            if((s1 == 1) & (s2 == 2)){
                if(p1 != p2){
                    if(s[p1] == t[p1])count_equal -= 1;
                    if(t[p2] == t[p1])count_equal += 1;
                    if(t[p2] == s[p2])count_equal -= 1;
                    if(s[p1] == s[p2])count_equal += 1;
                }
                swap(s[p1],t[p2]);
            }

            if((s1 == 2) & (s2 == 1)){
                if(p1 != p2){
                    if(t[p1] == s[p1])count_equal -= 1;
                    if(s[p2] == s[p1])count_equal += 1;
                    if(s[p2] == t[p2])count_equal -= 1;
                    if(t[p1] == t[p2])count_equal += 1;
                }

                swap(t[p1],s[p2]);
            }
             if((s1 == 2) & (s2 == 2)){
                if(t[p1] == s[p1]) count_equal -= 1;
                if(t[p2] == s[p1]) count_equal += 1;
                if(t[p2] == s[p2]) count_equal -= 1;
                if(t[p1] == s[p2]) count_equal += 1;
                swap(t[p1],t[p2]);
            }
        }

        else{
            if(count_equal >= to_comp) print("YES");
            else print("NO");
        }
    }

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
        //if(it == 2) return 0;
    }
    return 0;
}
