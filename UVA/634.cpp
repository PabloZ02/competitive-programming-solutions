#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double angleT(pt a, pt p, pt q) {
    return remainder(arg(q-a) - arg(p-a), 2*M_PI);
}

bool inside(pt a, vector<pt>& p) {
    double ans = 0;
    for(int i = 0, n = p.size(); i < n; i++)
        ans += angleT(a,p[i], p[(i+1)%n]);
    return fabs(fabs(ans) - 2*M_PI) < 1e-6;
}

int main() {
    int n;
    while(cin >> n, n) {
        vector<pt> p(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            p[i] = {xp,yp};
        }
        double xp,yp; cin >> xp >> yp;
        pt a = {xp,yp};
        if (inside(a,p)) cout << "T\n";
        else cout << "F\n";
    }
}