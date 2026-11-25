#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

bool half(pt p) {return p.y > 0 || (p.y == 0 && p.x < 0);}
double sq(pt p) {return p.x*p.x + p.y*p.y;}
double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}
double orient(pt a, pt b,pt c) {return cross(b-a,c-a);}
vector<pt> convHull(vector<pt>& p) {
    int p0 = 0, n = p.size();
    for(int i = 1; i < n; i++) {
        if (p[i].y > p[p0].y || (p[i].y == p[p0].y && p[i].x < p[p0].x))
        p0 = i;
    }
    iter_swap(p.begin(), p.begin() + p0);
    pt o = p[0];
    sort(++p.begin(), p.end(), [&o](pt v, pt w) {
        return make_tuple(half(v-o),0.0,sq(v-o)) < 
            make_tuple(half(w-o), cross(v-o,w-o), sq(w-o));
    });
    vector<pt> s = {p[n-1],p[0],p[1]};
    int i = 2;
    while(i < p.size()) {
        int j = s.size()-2;
        if (orient(s[j],s[j+1],p[i]) > 1e-6) s.push_back(p[i++]);
        else s.pop_back();
    }
    if (s[0] == s[s.size()-1]) s.pop_back();
    return s;
}

int main( ) {
    int n; 
    while(cin >> n, n >= 3) {
        vector<pt> poly(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            poly[i] = {xp,yp};
        }
        poly = convHull(poly);
        double area = 0;
        for(int i = 0 ; i < n; i++)
            area += cross(poly[i], poly[(i+1)%n]);
        area = abs(area)/2.0;
        double cx = 0,cy = 0;
        for(int i = 0; i< n; i++) {
            cx += (poly[i].x + poly[(i+1)%n].x) * 
                (poly[i].x*poly[(i+1)%n].y - poly[(i+1)%n].x*poly[i].y);
            cy += (poly[i].y + poly[(i+1)%n].y) * 
                (poly[i].x*poly[(i+1)%n].y - poly[(i+1)%n].x*poly[i].y);
        }
        cx = cx/(6.0*area);
        cy = cy / (6.0*area);    
        cout << setprecision(3) << fixed << cx << " " << cy << "\n";
    }
}