#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double dot(pt v, pt w) {return (conj(v)*w).x;}

double angle(pt v, pt w) {
    double cost = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cost)));
}


int main() {
    int n,m;
    double r = 10000.0/(2.0*M_PI);
    while(cin >> n >> m) {
        vector<pt> npoints(n);
        double ang = 0.0;
        for(int i = 0; i < n; i++) {
            double radang = ang*M_PI/180.0;
            npoints[i] = {r*cos(radang),r*sin(radang)};
            ang = (i+1)*360.0/(double)n;
            
        }
        vector<pt> nmpoints(n+m);
        ang = 0.0;
        for(int i = 0; i < n+m; i++) {
            double radang = ang*M_PI/180.0;
            nmpoints[i] = {r*cos(radang),r*sin(radang)};
            ang = (i+1)*360.0/(double)(n+m); 
        }
        double ans = 0;
        for(int i = 0; i < n; i++) {
            double mindist = DBL_MAX;
            for(int j = 0; j < n+m; j++) {
                double ang = angle(npoints[i],nmpoints[j]);
                mindist = min(mindist, (ang)*10000.0/(2*M_PI));
            }
            if (mindist > 1e-4) ans += mindist;

        }
        cout << setprecision(4) << fixed << ans << "\n";
    }
}