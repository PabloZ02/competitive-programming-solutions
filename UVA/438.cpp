#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

double cross(pt v, pt w) {return (conj(v)*w).imag();}
const double PI = 3.141592653589793;
int main() {
    double x1,y1,x2,y2,x3,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        pt p1 = {x1,y1}, p2 = {x2,y2}, p3 = {x3,y3};
        double d = abs(p2-p1) * abs(p3-p1) * abs(p3-p2) / abs(cross(p3-p1,p2-p1));
        cout << setprecision(2) << fixed << d*PI << "\n";
    }
}