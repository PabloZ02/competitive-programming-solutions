#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
bool half(pt p) {return p.y > 0 || (fabs(p.y) < 1e-6 && p.x < 0);}

vector<pt> convHull(vector<pt>& p) {
    int p0 = 0, n = p.size();
    for(int i = 1; i< n; i++)
    if (p[i].y > p[p0].y || (p[i].y == p[p0].y && p[i].x < p[p0].x)) p0 = i;
    iter_swap(p.begin(), p.begin() + p0);
    pt o = p[0];
    sort(++p.begin(),p.end(), [o](pt v, pt w) {
        return make_tuple(half(v-o),0.0,abs(v-o)) < 
            make_tuple(half(w-o),cross(v-o,w-o),abs(w-o));
    });
    vector<pt> s = {p[n-1],p[0],p[1]};
    int i = 2;
    while(i < n) {
        int j = s.size()-2;
        if (orient(s[j],s[j+1],p[i]) > 1e-6) s.push_back(p[i++]);
        else s.pop_back();
    }
    if (s[0] == s[s.size()-1]) s.pop_back();
    return s;
}

double area(vector<pt>& p) {
    double ans = 0.0;
    for(int i = 0, n = p.size(); i < p.size(); i++)
        ans += cross(p[i], p[(i+1)%n]);
    return abs(ans)/2.0;
}

int main() {
    int n; int tile = 1;
    while(cin >> n, n) {
        vector<pt> poly(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            poly[i] = {xp,yp};
        }
        double original_area = area(poly);
        poly = convHull(poly);
        double new_area = area(poly);
        double ans = 100.0 - 100.0*original_area/new_area;
        cout << "Tile #" << tile++ << "\n";
        cout << "Wasted Space = " << setprecision(2) << fixed << ans << " %\n";
        cout << "\n";
    }
}