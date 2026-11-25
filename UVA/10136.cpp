#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()


bool circle2PtsRad(pt p1, pt p2, double r, pt &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c = {(p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h,
            (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h};
return true; 
}

int main() {
    int TT; cin >> TT;
    bool passed = false;
    cin.ignore();cin.ignore();
    for(int _ = 0; _ < TT; _++) {
        if (passed) cout << "\n";
        else passed = true;
        string s; getline(cin,s);
        vector<pt> points;
        do {
            stringstream sstr(s);
            double xp,yp; sstr >> xp >> yp;
            points.push_back({xp,yp});
            getline(cin,s);
        } while(s != "");
        double r = 2.5;
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++) {
            pt c1,c2;
            circle2PtsRad(points[i],points[j],r,c1);
            int fit = 0;
            for(int k = 0; k < n; k++) {
                bool equ = abs(abs(points[k]-c1)-r) < 1e-6;
                fit += abs(points[k]-c1) < r || equ;
            }
            ans = max(ans,fit); fit = 0;
            circle2PtsRad(points[j],points[i],r,c2);
            for(int k = 0; k < n; k++) {
                bool equ = abs(abs(points[k]-c2)-r) < 1e-6;
                fit += abs(points[k]-c2) <  r || equ;
            }
            ans = max(ans,fit);
        }
        cout << ans << "\n";
    }
}