#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
int main() {
    double r,n;
    while(cin >> r >> n) {
        double theta = 2*M_PI/n;
        pt p = {cos(theta)*r,sin(theta)*r};
        pt org = {r,0};
        double h = abs((p+org)/2.0), b = abs(p-org);
        cout << fixed << setprecision(3) << 
            h * b / 2.0 * n << "\n";
    }
}