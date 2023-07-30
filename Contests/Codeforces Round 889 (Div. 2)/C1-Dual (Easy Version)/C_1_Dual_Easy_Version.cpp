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
#define f_rev(start,i,end) for(int i = start; i > end; i--)
#define lower(v,val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define upper(v,val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define max_arr(v) *max_element(v.begin(), v.end())
#define min_arr(v) *min_element(v.begin(), v.end())
#define print(var) cout << var << endl
#define print_vec(v) for (auto it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
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

// SOLVE
void solve(){

    int n; cin >> n;
    int max = -21;
    int max_i = -1;
    int min = 21;
    int min_i = -1;
    VI a(n);

    f(0,i,n) {
        cin >> a[i];
        if(a[i] > max){
            max_i = i; 
            max = a[i];
        }

        if(a[i] < min){
            min_i = i;
            min = a[i];
        } 
    }

    auto a2 = a;

    VPI pairs;
    VPI pairs2;

    bool bool1 = false;
    bool bool2 = false;
    
    if(a[max_i] > 0){
        bool1 = true;
        f(1,i,n){
           while(a[i] < a[i-1]){
                a[i] += a[max_i];
                pairs.push_back(make_pair(i+1,max_i+1));
                if(a[i] > a[max_i]) max_i  = i;
           }
           
        }
    }

    if(a2[min_i] < 0){
        bool2 = true;
        f_rev(n-2,i,-1){
           while(a2[i] > a2[i+1]){
                a2[i] += a2[min_i];
                pairs2.push_back(make_pair(i+1,min_i+1));
                if(a2[i] < a2[min_i]) min_i  = i;
           }
        }
    }
  
    if((bool1 == false) & (bool2 == false)){
        print(0);
        return;
    }
    if((bool1 == false) & (bool2 == true)){
        print(pairs2.size());
        f(0,i,pairs2.size()){
            print_pair(pairs2[i]);
        }
    }

    if((bool1 == true) & (bool2 == false)){
        print(pairs.size());
        f(0,i,pairs.size()){
            print_pair(pairs[i]);
        }
    }

     if((bool1 == true) & (bool2 == true)){
         if(pairs.size() < pairs2.size()){
        print(pairs.size());
        f(0,i,pairs.size()){
            print_pair(pairs[i]);
        }
    }
    else{
        print(pairs2.size());
        f(0,i,pairs2.size()){
            print_pair(pairs2[i]);
        }
    }
     }




   
    
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        cout<< "TESTCASE:  " <<  it << endl;
        solve();
        //if(it == 2) return 0;
    }
    return 0;
}