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

bool check_in_circle(int Cx, int Cy, float R, int Px, int Py){

    float dist = pow(Cx - Px, 2) + pow(Cy - Py, 2);
    if(dist <= R*R) return true;
    else return false;
}

bool circles_touching(int Ax,int Ay, int Bx,int By, float w){
    float dist = pow(Ax - Bx, 2) + pow(Ay - By, 2);
    if(dist <= 4*w*w) return true;
    else return false;
}

// SOLVE
void solve(){

    int Px,Py,Ax,Ay,Bx,By;
    cin >> Px >>  Py >> Ax >> Ay >> Bx >> By;

    cout << setprecision(10) << endl;

    double low = 0;
    double high = pow(10,7);


    double best = high;
    double prev = -1;

    while(low <= high){
        double mid = (low + high) / 2;
        if(abs(mid - best) < 0.00000001){
            break;
        }
        bool start_in_A = check_in_circle(Ax,Ay,mid,0,0);
        bool end_in_A = check_in_circle(Ax,Ay,mid,Px,Py);

        bool start_in_B = check_in_circle(Bx,By,mid,0,0);
        bool end_in_B = check_in_circle(Bx,By,mid,Px,Py);

        bool touch =  circles_touching(Ax,Ay,Bx,By,mid);

        bool pos = (start_in_A & end_in_A) or (start_in_B & end_in_B) or (start_in_A & end_in_B & touch) or (start_in_B & end_in_A & touch);

        if(pos){
            high = mid;
            best = mid;
            prev = mid;
        }

        else{
            low = mid;
        }
    }

    print(best);

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