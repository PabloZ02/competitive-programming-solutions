#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

bool comp(pt v, pt w) {
    return v.x < w.x || (v.x == w.x && v.y < w.y);
}

int main() {
    int tt; cin >> tt;
    for(int _ = 0; _ < tt; _++) {
        int n; cin >> n;
        vector<pt> points(n);
        for(int i = 0; i < n; i++) {
            int xp,yp; cin >> xp >> yp;
            points[i] = {xp,yp};
        }
        sort(points.begin(),points.end(),comp);
        pt s = (points[0] + points[n-1]) / 2.0;
        bool can = true;
        for(int i = 1; i < n-1; i++) {
            can = false;
            for(int j = 0; j < n && !can; j++) {
                pt mid = (points[i] + points[j]) / 2.0;
                can = abs(mid-s) < 1e-6;
            }
            if (!can) break;
        }
        if (can) cout << "yes\n";
        else cout << "no\n";
    }
}