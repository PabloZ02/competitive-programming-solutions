#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()
double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
double inDisk(pt a, pt b, pt p) {return dot(a-p,b-p) <= 0;}
bool onSegment(pt a, pt b, pt p) {
    return (fabs(orient(a,b,p)) < 1e-6) && inDisk(a,b,p);
}
bool half(pt p) {return p.y > 0 || (p.y == 0 && p.x < 0);}

bool above(pt a, pt p) {
    return p.y >= a.y;
}
bool crossesRay(pt a, pt p, pt q) {
    return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}
bool inPoly(vector<pt>& p, pt a) {
    int ans = 0;
    for(int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n],a)) return true;
        ans += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return ans & 1;
}

vector<pt> convHull(vector<pt>& p) {
    int p0 = 0, n = p.size();
    if (n <= 3) return p;
    for(int i = 1; i < n; i++) {
        if (p[i].y > p[p0].y || (p[i].y == p[p0].y && p[i].x > p[p0].x))   
            p0 = i;
    }
    iter_swap(p.begin(), p.begin() + p0);
    pt pivot = p[0];
    sort(++p.begin(), p.end(), [pivot](pt v, pt w){
        return make_tuple(half(v-pivot),0.0,abs(v-pivot))
            < make_tuple(half(w-pivot), cross(v-pivot,w-pivot), abs(w-pivot));
    });
    vector<pt> s = {p[n-1],p[0],p[1]};
    int i = 2;
    while(i < p.size()) {
        int j = s.size()-2;
        if (orient(s[j],s[j+1],p[i]) > 0) s.push_back(p[i++]);
        else s.pop_back();
    }
    if (s[0] == s[s.size()-1]) s.pop_back();
    return s;
}

double angleT(pt a, pt p, pt q) {
    return remainder(arg(q-a) - arg(p-a), 2*M_PI);
}

bool inside(pt a, vector<pt>& p) {
    for(int i = 0, n= p.size(); i < n; i++) 
        if (onSegment(p[i],p[(i+1)%n],a)) return true;
    double ampli = 0;
    for(int i = 0, n = p.size(); i < n; i++)
        ampli += angleT(a, p[i], p[(i+1)%n]);
    return fabs(fabs(ampli) - 2*M_PI) < 1e-6;
}

int main() {
    int c,r,o;
    int tt = 1;
    while(cin >> c >> r >> o) {
        if (c+r+o == 0) break;
        cout << "Data set " << tt++ << ":\n";
        vector<pt> cops(c),robs(r),oths(o);
        for(int i = 0; i < c; i++) {
            double xp,yp; cin >> xp >> yp;
            cops[i] = {xp,yp};
        }
        for(int i = 0; i < r; i++) {
            double xp,yp; cin >> xp >> yp;
            robs[i] = {xp,yp};
        }
        for(int i = 0; i < o; i++) {
            double xp,yp; cin >> xp >> yp;
            oths[i] = {xp,yp};
        }
        vector<pt> chc = convHull(cops), chr = convHull(robs);
        for(int i = 0; i < o; i++) {
            cout << "     Citizen at " << oths[i] << " is ";
            if (chc.size() > 2 && inPoly(chc,oths[i])) cout << "safe.\n";
            else if (chr.size() > 2 && inPoly(chr,oths[i])) cout << "robbed.\n";
            else cout << "neither.\n";
        }
        cout << "\n";
    }
}