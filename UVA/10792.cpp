#include<bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double dot(pt v, pt w) {return (conj(v)*w).x;}
int main() {
    int n; cin >> n;
    for(int tt = 1; tt <= n; tt++) {
        double r,d,h; cin >> r >> d >> h;
        pt center = {0,r};

        pt hardy = {sqrt(r*r - (h-r)*(h-r)),h};
        pt rt = {1,0};
        double angle = acos(dot(rt,hardy-center) / abs(rt) / abs(hardy-center));
        if (angle < M_PI) angle = 2*M_PI - angle;
        double low = 0.0;
        double high =  M_PI;
        pt laurel;
        while(abs(high-low) > 1e-9) {
            double theta = (low+high) / 2.0;
            laurel = {center.x + r * cos(angle-theta), center.y + r * sin(angle-theta)};
            pt f = {center.x + r * cos(angle-theta/2.0), center.y + r * sin(angle-theta/2.0)};
            pt e = (laurel + hardy) / 2.0;
            if (abs(e-f) < d) low = theta;
            else high = theta;
        }
        cout << "Case " << tt << ": ";
        cout << setprecision(4) << fixed << laurel.y << "\n";
        
    }
}