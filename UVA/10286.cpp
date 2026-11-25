#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

int main() {
    double f;
    double theta = M_PI*(180.0 - 9.0 - 108.0) / 180.0;
    double t_108 = M_PI * 108.0 / 180.0;
    while(cin >> f) {
        cout << setprecision(10) << fixed << f * sin(t_108) / sin(theta) << "\n";
    }
}