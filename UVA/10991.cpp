#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;


int main() {
    int n; cin >> n;
    while(n--) {
        double r1,r2,r3; cin >> r1 >> r2 >> r3;
        double a = r1+r2, b = r2+r3, c = r1+r3;
        double t3 = acos((b*b + c*c - a*a)/(2.0*c*b));
        double t2 = acos((a*a + b*b - c*c)/(2.0*a*b));
        double t1 = acos((a*a + c*c - b*b)/(2.0*a*c));

        double s = (a+b+c)/2, area = sqrt(s*(s-a)*(s-b)*(s-c));
        double arcs = t3/2.0*r3*r3 + t2/2.0*r2*r2 + t1/2.0*r1*r1;
        cout << setprecision(6) << fixed << area-arcs << "\n";
    }
}