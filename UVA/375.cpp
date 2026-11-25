#include <bits/stdc++.h>

using namespace std;
typedef complex<long double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

/*pt inter(pt v1, double c1, pt v2, double c2) {
    double d = cross(v1,v2);
    return (v2*c1 - v1*c2) / d;
}*/

/*pair<pt,pt> bisector(pt a, pt b, pt c) {
    double ac = abs(a-c), bc = abs(b-c), ab = abs(a-b);
    double cd = bc / (ab/ac + 1.0);
    pt d = c + (b-c)/bc*cd;
    return {a,d};
}*/

int main() {
    int tt; cin >> tt;
    bool passed = false;
    for(int _ = 0; _ < tt; _++) {
        if (passed) cout << "\n";
        else passed = true;
        long double b,h;
        cin >> b >> h;
        long double ans = 0.0;
        vector<long double> answers;
        while(1) {
            long double hip = hypotl(h,b/2.0);
            long double r = (b*h)/(b+2.0*hip);
            if (r < 0.000001) break;
            answers.push_back(r*acos(-1.0L) * 2.0);
            
            long double factor = 1.0 - 2.0 * r / h;
            b *= factor;
            h -= 2.0*r;
        }
        for(int i = answers.size()-1; i >= 0; i--) ans += answers[i];
        int ansint = ans; ansint /= 10;
        int digits = 1;
        while(ansint > 0) {ansint /= 10; digits++;}
        for(int i = 0; i < 6-digits;i++) cout << " ";
        cout << fixed << setprecision(6) << ans << "\n";
    }
}