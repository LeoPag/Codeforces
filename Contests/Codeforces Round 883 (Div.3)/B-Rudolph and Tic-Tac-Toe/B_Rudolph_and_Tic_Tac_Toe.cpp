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
typedef vector<char> VC;
typedef vector<vector<int> > VVI;
typedef vector<vector<ll> > VVL;
typedef vector<vector<PL> > VVPL;
typedef vector<PL> VPL;
typedef vector<PI> VPI;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
  
void solve(){
    VC first_row(3);
    VC second_row(3);
    VC third_row(3);

    for(int i = 0; i < 3; i++) cin >> first_row[i];
    for(int i = 0; i < 3; i++) cin >> second_row[i];
    for(int i = 0; i < 3; i++) cin >> third_row[i];


    if((first_row[0] == '+') & (first_row[1] == '+') & (first_row[2] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[0] == 'X') & (first_row[1] == 'X') & (first_row[2] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[0] == 'O') & (first_row[1] == 'O') & (first_row[2] == 'O')){
        cout << 'O' << endl;
        return;
    }

    if((second_row[0] == '+') & (second_row[1] == '+') & (second_row[2] == '+')){
        cout << '+' << endl;
        return;
    }
    if((second_row[0] == 'X') & (second_row[1] == 'X') & (second_row[2] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((second_row[0] == 'O') & (second_row[1] == 'O') & (second_row[2] == 'O')){
        cout << 'O' << endl;
        return;
    }

    if((third_row[0] == '+') & (third_row[1] == '+') & (third_row[2] == '+')){
        cout << '+' << endl;
        return;
    }
    if((third_row[0] == 'X') & (third_row[1] == 'X') & (third_row[2] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((third_row[0] == 'O') & (third_row[1] == 'O') & (third_row[2] == 'O')){
        cout << 'O' << endl;
        return;
    }





    if((first_row[0] == '+') & (second_row[0] == '+') & (third_row[0] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[0] == 'X') & (second_row[0] == 'X') & (third_row[0] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[0] == 'O') & (second_row[0] == 'O') & (third_row[0] == 'O')){
        cout << 'O' << endl;
        return;
    }


     if((first_row[1] == '+') & (second_row[1] == '+') & (third_row[1] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[1] == 'X') & (second_row[1] == 'X') & (third_row[1] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[1] == 'O') & (second_row[1] == 'O') & (third_row[1] == 'O')){
        cout << 'O' << endl;
        return;
    }

     if((first_row[2] == '+') & (second_row[2] == '+') & (third_row[2] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[2] == 'X') & (second_row[2] == 'X') & (third_row[2] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[2] == 'O') & (second_row[2] == 'O') & (third_row[2] == 'O')){
        cout << 'O' << endl;
        return;
    }



    if((first_row[0] == '+') & (second_row[1] == '+') & (third_row[2] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[0] == 'X') & (second_row[1] == 'X') & (third_row[2] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[0] == 'O') & (second_row[1] == 'O') & (third_row[2] == 'O')){
        cout << 'O' << endl;
        return;
    }

    if((first_row[2] == '+') & (second_row[1] == '+') & (third_row[0] == '+')){
        cout << '+' << endl;
        return;
    }
    if((first_row[2] == 'X') & (second_row[1] == 'X') & (third_row[0] == 'X')){
        cout << 'X' << endl;
        return;
    }
    if((first_row[2] == 'O') & (second_row[1] == 'O') & (third_row[0] == 'O')){
        cout << 'O' << endl;
        return;
    }

    cout << "DRAW" << endl;
    
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