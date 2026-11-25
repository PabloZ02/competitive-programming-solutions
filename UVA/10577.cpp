#include <bits/stdc++.h>

using namespace std;

typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}
double dot(pt v, pt w) {return (conj(v)*w).x;}
pt inter(pt v1, pt v2, double c1, double c2) {
    double d = cross(v1,v2);
    return (v2*c1 - v1*c2) / d;
}

int main() {
    int n; 
    int p = 1;
    while(cin >> n, n != 0) {
        vector<pt> tr(3);
        for(int i = 0; i < 3; i++) {
            double xx,yy; cin >> xx >> yy;
            tr[i] = {xx,yy};
        }
        double area = abs(cross(tr[2]-tr[0],tr[1]-tr[0]))/2.0;
        double r = abs(tr[2]-tr[1]) * abs(tr[2]-tr[0]) * abs(tr[1]-tr[0]) / (4.0 * area);

        pt mid1 = (tr[0]+tr[1]) / 2.0;
        pt perp1 = mid1 + (pt){-(tr[1]-tr[0]).y, (tr[1]-tr[0]).x};

        pt mid2 = (tr[0]+tr[2]) / 2.0;
        pt perp2 = mid2 + (pt){-(tr[2]-tr[0]).y, (tr[2]-tr[0]).x};

        pt v1 = perp1-mid1, v2 = perp2-mid2;
        double c1 = cross(v1,mid1), c2 = cross(v2,mid2);

        pt center = inter(v1,v2,c1,c2);

        pt start = tr[0];
        double theta = acos(dot(start-center, {1,0}) / abs(start-center) / abs((pt){1,0}));  
        double maxx = start.x, minx = start.x, maxy = start.y, miny = start.y;
        for(int i = 0; i < n; i++) {
            theta += (2*M_PI) / n;
            start = {center.x + r*cos(theta), center.y + r*sin(theta)};
            maxx = max(maxx, start.x), minx = min(minx, start.x);
            maxy = max(maxy, start.y), miny = min(miny, start.y);
        }
        cout << "Polygon " << p++ << ": ";
        cout << setprecision(3) << fixed << (maxx-minx) * (maxy-miny) << "\n";
    }
}