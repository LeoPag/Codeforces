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
typedef vector<char> VC;
typedef vector<VC> VVC;
// SOLVE
void solve(){

    int n,m; cin >> n >> m;
    VVC mat(n,VC(m));

    f(0,i,n){
        f(0,j,m){
            cin >> mat[i][j];
        }
    }


    VVC ans(n,VC(m,'.'));

    VI cols_horiz(m,-1);
    VI rows_vert(n,-1);

    f(0,i,n){
        f(0,j,m){
            if(mat[i][j] == '.') continue;
            if(mat[i][j] == 'R') continue;
            if(mat[i][j] == 'D') continue;

            if(mat[i][j] == 'L'){

                if(cols_horiz[j] == -1){
                    ans[i][j] = 'W';
                    ans[i][j+1] = 'B';
                    cols_horiz[j] = i;
                }

                else{
                    int idx = cols_horiz[j];
                    ans[i][j] = ans[idx][j+1];
                    ans[i][j+1] = ans[idx][j];
                    cols_horiz[j] = -1;
                }
            }

            if(mat[i][j] == 'U'){

                if(rows_vert[i] == -1){
                    ans[i][j] = 'W';
                    ans[i+1][j] = 'B';
                    rows_vert[i] = j;
                }

                else{
                    int idx = rows_vert[i];
                    ans[i][j] = ans[i+1][idx];
                    ans[i+1][j] = ans[i][idx];
                    rows_vert[i] = -1;
                }
            }
        }
    }

    f(0,i,m){
        if(cols_horiz[i] != -1){
            print(-1);
            return;
        }
    }

    f(0,i,n){
        if(rows_vert[i] != -1){
            print(-1);
            return;
        }
    }

    f(0,i,n){
        f(0,j,m){
            cout << ans[i][j];
        }
        cout << endl;
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