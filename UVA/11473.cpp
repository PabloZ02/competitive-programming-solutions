#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    int TT; cin >> TT;
    for(int tt = 1; tt <= TT; tt++) {
        cout << "Road #" << tt << ":\n";
        int n; double t; cin >> n >> t;
        vector<pt> p(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            p[i] = {xp,yp};
        }
        double peri = 0.0;
        for(int i = 0; i < n-1; i++) peri += abs(p[i+1]-p[i]);
        double gap = peri/(t-1);
        double cur_gap = gap; int ind = 0;
        cout << setprecision(2) << fixed << p[0].x << " " << p[0].y << "\n";
        pt cur_pt = p[0];
        while(ind < n-1) {
            if (fabs(cur_gap - abs(cur_pt-p[ind+1])) < 1e-6) {
                cur_gap = gap;
                ind++;
                cout << p[ind].x << " " << p[ind].y << "\n";
                cur_pt = p[ind];
            }
            else if (cur_gap > abs(cur_pt-p[ind+1])) {
                cur_gap -= abs(cur_pt-p[ind+1]);
                ind++;
                cur_pt = p[ind];
            }
            else {
                pt v = p[ind+1]-cur_pt; v = v/abs(v);
                cur_pt = cur_pt + cur_gap*v;
                cout << cur_pt.x << " " << cur_pt.y << "\n";
                cur_gap = gap;
            }
        }
        cout << "\n";
    }
    
}