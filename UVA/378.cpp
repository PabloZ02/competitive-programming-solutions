#include <bits/stdc++.h>

using namespace std;

typedef complex<double> pt;
#define x real()
#define y imag()

struct line {
    pt v; 
    double c;
};

double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}

bool inter(line l1, line l2, pt & out) {
    double d = cross(l1.v,l2.v);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d;
    return true;
}

double side(line l,pt p) {return cross(l.v,p)-l.c;}

int main() {
    int n; cin >> n;
    cout << "INTERSECTING LINES OUTPUT\n";
    for(int _ = 0; _ < n; _++) {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pt v1 = {x1-x2,y1-y2};
        line l1 = {v1, cross(v1,{x2,y2})};
        pt v2 = {x3-x4,y3-y4};
        line l2 = {v2, cross(v2, {x4,y4})};
        pt out;
        if (inter(l1,l2,out)) {
            cout << "POINT " << setprecision(2) << fixed << out.x << " " << out.y << "\n";
        }
        else if (abs(side(l1,{x3,y3})) < 1e-6) cout << "LINE\n";
        else cout << "NONE\n";
    }
    cout << "END OF OUTPUT\n";
}