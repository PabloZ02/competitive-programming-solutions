#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

struct line {
    pt v; double c;
};

double cross(pt v, pt w) {return (conj(v)*w).y;}

bool inter(line l1, line l2, pt& out) {
    double d = cross(l1.v,l2.v);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d;
    return true;
}

int main() {
    double a,b,c,d,e,f;
    while(1) {
        cin >> a >> b >> c >> d >> e >> f;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) break;
        line l1,l2;
        l1.v = {b,-a}; l1.c = c;
        l2.v = {e,-d}; l2.c = f;
        pt out;
        cout << setprecision(2) << fixed;
        if (inter(l1,l2,out)) {
            cout << "The fixed point is at " << out.x << " " << out.y << ".\n";
        } else cout << "No fixed point exists.\n";
    }   
}