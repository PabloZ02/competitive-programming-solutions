#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    double l,c,r1,r2;
    while(cin >> l >> c >> r1 >> r2, (l != 0 || c != 0 || r1 != 0 || r2 != 0)) {
        if (r1+r1 > l || r1+r1 > c || r2+r2 > l || r2+r2 > c) {
            cout << "N\n"; continue;
        }
        pt c1 = {r1,r1};
        pt c2 = {l-r2,c-r2};
        if (abs(c1-c2) < r1+r2) cout << "N\n";
        else cout << "S\n";
    }
}