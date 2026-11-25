#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

int main() {
    int tt;
    while(cin >> tt, tt) {
        double ftarea = 0.0; cin.ignore();
        while(tt--) {
            double tarea = 0.0;
            string lline; getline(cin,lline);
            stringstream sstream(lline);
            double t; sstream >> t;
            vector<pt> poly; double xp,yp;
            while(sstream >> xp >> yp) {
                poly.push_back({xp,yp});
            }
            for(int i = 0; i < poly.size()-1; i++)
                tarea += cross(poly[i],poly[i+1]);
            ftarea += t*abs(tarea)/2.0;
        }
        double r,t; cin >> r >> t;
        double marea = M_PI*r*r*t;
        long long ans = ftarea/marea;
        cout << ans << "\n";
    }
}