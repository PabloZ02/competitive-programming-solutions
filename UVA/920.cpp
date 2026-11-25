#include <bits/stdc++.h>

using namespace std;

typedef complex<double> pt;
#define x real()
#define y imag()
bool comp(pt v, pt w) {
    return v.x < w.x;
}

int main() {
    int TT; cin >> TT;
    for(int _ = 0; _ < TT; _++) {
        int n; cin >> n;
        vector<pt> peaks(n);
        for(int i = 0; i < n; i++) {
            double x1,y1; cin >> x1 >> y1;
            peaks[i] = {x1,y1};
        }
        sort(peaks.begin(), peaks.end(),comp);
        double h = 0;
        double ans = 0;
        for(int i = n-2; i >= 0; i--) {
            if (peaks[i].y > h) {
                double m = (peaks[i].y-peaks[i+1].y)/(peaks[i+1].x-peaks[i].x);
                double c = peaks[i].y + m*peaks[i].x;
                double xh = (c - h) / m;
                
                ans += hypot(xh-peaks[i].x, peaks[i].y-h);
                h = peaks[i].y;

            }
        }
        cout << setprecision(2) << fixed << ans << "\n";
    }
}