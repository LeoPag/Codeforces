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

typedef vector<string> VS;
typedef set<int> SI;


int binary_to_dec(string s){
    int n  = s.size();
    int dec = 0;
    f(0,i,n){
        if(s[i] == '1') dec += pow(2,n-i-1);
    }
    return dec;
}
int INF = 10000000;
int find_min(VI& distances, VI& visited){
    int min_dist = INF;
    int min_idx = -1;
    for(int i = 0; i < distances.size(); i++){
        if((visited[i] == 0) & (distances[i] < min_dist)){
            min_dist = distances[i];
            min_idx = i;
        }
    }
    return min_idx;
}

// SOLVE
void solve(){

    int n,m; cin >> n >> m;

    VVPI adj_list(pow(2,n));

    string start_state; cin >> start_state;
    int start_int = binary_to_dec(start_state);
    
    VS heals;
    VS side_effects;
    VI days;

    f(0,i,m){
        int d; cin >> d;
        days.push_back(d);
        string h; cin >> h;
        heals.push_back(h);
        string se; cin >> se;
        side_effects.push_back(se);
    }

    f(0,i,pow(2,n)){
        f(0,j,m){
            int res = 0 & (~binary_to_dec(heals[j]));
            int end_state = (i & (~binary_to_dec(heals[j]))) | binary_to_dec(side_effects[j]);
            adj_list[i].push_back(make_pair(end_state, days[j]));
        }
    }

    VI distances(pow(2,n), INF);
    VI visited(pow(2,n), 0);

    distances[start_int] = 0;

    while (true){

        int min_idx = find_min(distances, visited);
        if(min_idx == -1) break;

        visited[min_idx] = 1;

        for(auto it = adj_list[min_idx].begin(); it != adj_list[min_idx].end(); it ++){

            int end = it->first;
            distances[end] = min(distances[end], distances[min_idx] + it->second);
        }

    }

    if(distances[0] != INF) print(distances[0]);
    else print(-1);
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