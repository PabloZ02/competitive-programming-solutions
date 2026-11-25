#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
#define x real()
#define y imag()

bool half(pt p) {return p.y > 1e-9 || (fabs(p.y) < 1e-9 && p.x < 0);}
ld cross(pt v, pt w) {return (conj(v)*w).y;}
ld orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
vector<pt> convHull(vector<pt> p) {
    int k = 0, n = p.size();
    if (n < 3) return p;
    for(int i = 0; i < n; i++)
    if (p[i].y > p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x)) k= i;
    iter_swap(p.begin(), p.begin() + k);
    pt o = p[0];
    sort(++p.begin(), p.end(), [&o](pt v, pt w){
        return 0.0 < cross(v-o,w-o);
    });
    vector<pt> s = {p[n-1],p[0],p[1]};
    int i = 2;
    while(i < p.size()) {
        int j = s.size()-2;
        if (orient(s[j],s[j+1],p[i]) > 1e-9) s.push_back(p[i++]);
        else if(s.size() > 2) s.pop_back();
        else s.push_back(p[i++]);
    }
    if (s[0] == s[s.size()-1]) s.pop_back();
    return s;
}

int main() {
    int TT; cin >> TT;
    while(TT--) {
        double l; int n;
        cin >> l >> n;
        vector<pt> poly(n);
        for(int i = 0; i< n; i++) {
            double xp,yp; cin >> xp >> yp;
            poly[i] = {xp,yp};
        }
        poly = convHull(poly); n = poly.size();
        double ans = 0.0;
        for(int i = 0; i< n; i++)
            ans += abs(poly[i] - poly[(i+1)%n]);
        cout << setprecision(5) << fixed << max(ans,l) << "\n";

    }
}