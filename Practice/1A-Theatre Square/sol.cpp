#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cout.precision(22);
    double m,n,a;
    cin >> m >> n >> a;
    cout << ceil(m/a) * ceil(n/a) << endl;
    return 0;
}
