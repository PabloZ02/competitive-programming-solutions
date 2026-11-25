#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    int n,T; 
    while(cin >> n >> T) {
    pt p = {0,0};
    for(int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        double r; int t; cin >> r >> t;
        double rott = T%t;
        double theta = t == 0 ? 0 : rott*2*M_PI/((double) t);
        pt np = {p.x + r*cos(theta),p.y + r*sin(theta)};
        cout << setprecision(4) << fixed << abs(np);
        swap(p,np);
    }
    cout << "\n";
    }
}