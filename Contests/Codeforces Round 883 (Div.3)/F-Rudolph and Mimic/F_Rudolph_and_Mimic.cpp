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
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
#define print(var) cout << var << endl
#define print_vec(vec) f(0,i,vec.size()) cout << vec[i] << " "; cout << endl
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

    int n; cin >> n;
    VI freq_1(10,0);

    VI a(n);
    f(0,i,n) {
        cin >> a[i];
        freq_1[a[i]] += 1;
    }

    VI freq_2(10,0);
    int object_type = -1;
    while (object_type == -1){
        cout << "- " << 0 << endl;
        cout << endl;
        cout.flush();

        freq_2 = VI(10,0);
        f(0,i,n) {
            cin >> a[i];
            freq_2[a[i]] += 1;
        }
        f(0,j,10){
            if(freq_2[j] > freq_1[j]) object_type = j;
        }
    }

    cout << "- " << n - freq_2[object_type] << " ";

    f(0,i,n){
        if(a[i] != object_type) cout << i + 1 << " ";
    }
    cout << endl;
    cout.flush();
    cout << endl;

    int ans = -1;

    while(ans == -1){
        VI b(freq_2[object_type],0);
        f(0,i,freq_2[object_type]) {
            cin >> b[i];
            if(b[i] != object_type) ans = i+1;
        }
        if(ans != -1) break;
        cout << "- " << 0 << endl;
        cout.flush();
        cout << endl;
    }

    cout << "! " << ans << endl;
    cout.flush();
    cout << endl;
    cout << endl;
}

int main(){
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout<< "TESTCASE:  " <<  it << endl;
        solve();
    }
    return 0;
}
