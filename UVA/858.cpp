#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n; cin>> n;
        vector<pt> poly(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            poly[i] = {xp,yp};
        }
        double threshold; cin >> threshold;
        int xgoal; cin >> xgoal;
        vector<double> ycoords;
        for(int i = 0; i < n; i++) {
            pt p1 = poly[i], p2 = poly[(i+1)%n];
            if (p1.x > p2.x) swap(p1,p2);
            if (p1.x < xgoal && p2.x > xgoal) {
                double m = (p2.y-p1.y)/(p2.x-p1.x);
                ycoords.push_back(m*(xgoal-p1.x) + p1.y);
            }
        }
        sort(ycoords.begin(),ycoords.end());
        double ans = 0;
        for(int i = 0; i < ycoords.size(); i += 2) {
            ans += ycoords[i+1] - ycoords[i];
        }
        if (threshold - ans < 1e-6) cout << "YES\n";
        else cout << "NO\n";
    }
}