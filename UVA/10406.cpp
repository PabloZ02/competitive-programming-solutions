#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int prev(int i, int n) {return i == 0 ? n-1 : i-1;}
double cross(pt v, pt w) {return (conj(v)*w).y;}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
pt inter(pt v1, double c1, pt v2, double c2) {
    double d = cross(v1,v2);
    return (c1*v2 - c2*v1)/d;
}


vector<pt> cut(pt a, pt b, vector<pt> q) {
    vector<pt> p; int n = q.size();
    for(int i = 0; i < n; i++) {
        double left1 = orient(a,b,q[i]), left2 = orient(a,b,q[(i+1)%n]);
        if (left1 < 1e-6) p.push_back(q[i]);
        if (left1*left2 < -1e-6) {
            pt v1 = q[(i+1)%n] - q[i], v2 = b-a;
            double c1 = cross(v1,q[i]), c2 = cross(v2,a);
            p.push_back(inter(v1,c1,v2,c2));
        }
    }
    int offset = 0; bool found = false;
    for(int i = 0; i < n && !found; i++)
    for(int j = 0; j < n && !found; j++) {
        if (q[i] == p[j]) {
            offset = j-i; found = true;
        }
    }
    offset = (offset + n) % n;
    vector<pt> newp(n);
    for(int i = 0; i< n; i++) {
        newp[i] = p[(offset+i)%n];
    }
    swap(p,newp);
    return p;
}

int main() {
    double d; int n;
    while(cin >> d >> n, (d != 0 || n != 0)) {
        vector<pt> poly(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            poly[i] = {xp,yp};
        }
        vector<vector<pt>> new_polys(n);
        for(int i = 0; i < n; i++) {
            pt v = poly[(i+1)%n] - poly[i];
            double sign = orient(poly[i], poly[(i+1)%n], poly[(i+2)%n]) > 0 ? 1 : -1;
            pt perpv = sign * (pt){-v.y,v.x};
            pt a = poly[i] + perpv/abs(perpv)*d, b = poly[(i+1)%n]+ perpv/abs(perpv)*d;
            vector<pt> npoly = cut(a,b,poly);
            new_polys[i] = npoly;
        }
        for(int i = 0; i < n; i++) {
            pt offset = {0,0};
            for(int pn = 0; pn < n; pn++)
                offset += (new_polys[pn][i] - poly[i]);
            poly[i] += offset;
        }
        double area = 0;
        for(int i = 0; i< n; i++)
            area += cross(poly[i], poly[(i+1)%n]);
        cout << fixed << setprecision(3) << abs(area)/2.0 << "\n";
    }
}