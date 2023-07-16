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


int n,m,q;

//void build_prefix_sums(VI& arr_q)



bool check_bool(VI& arr_q, VVI& intervals, int q_max){

    VI prefix_sums(n+1,0);
    VI arr(n+1,0);

    f(0,i,q_max + 1){
        arr[arr_q[i]] = 1;
    }

    prefix_sums[0] = 0;

    f(1,i,n+1){
        prefix_sums[i] = prefix_sums[i-1] + arr[i];
    }

    f(0,i,m){
        int requested_size = ((intervals[i][1] - intervals[i][0] + 1) / 2) + 1;

        if(prefix_sums[intervals[i][1]] - prefix_sums[intervals[i][0]-1] >= requested_size) return true;
    }
    return false;

}


//SOLVE
void solve(){

    cin >> n >> m;
    VVI intervals(m);

    f(0,i,m){
        int l,r; cin >> l >> r;
        intervals[i].push_back(l);
        intervals[i].push_back(r);
    }

    cin >> q;
    VI arr_q(q+1,0);
    f(1,i,q+1){
        int q_i; cin >> q_i;
        arr_q[i] = q_i;
    }

    if (check_bool(arr_q,intervals, q) == 0){
        cout << -1 << endl;
        return;
    }

    int low = 1;
    int high = q;
    int best = q;

    while (low <= high){
        int mid = (high + low) / 2;

        bool check = check_bool(arr_q,intervals, mid);

        if(check == 1){
            best = mid;
            high = mid - 1;
        }

        else{
            low =mid + 1;
        }
    }

    cout << best << endl;

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
