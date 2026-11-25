#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()
double dot(pt a, pt b) {return (conj(a)*b).x;}
double angle(pt a, pt b) {return acos(dot(a,b)/abs(a)/abs(b));}
double cross(pt a, pt b) {return (conj(a)*b).y;}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

double angleT(pt a, pt p, pt q) {
    return remainder(arg(q-a) - arg(p-a), 2*M_PI);
}

bool inside(vector<pt>& p, pt a) {
    double ampli = 0;
    for(int i = 0, n = p.size(); i < n; i++) {
        ampli += angleT(a,p[i], p[(i+1)%n]);
    }
    return (fabs(ampli - 2*M_PI) < 1e-6);
}

double areaP(vector<pt>& p) {
    double area = 0;
    for(int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area) /2.0;
}
bool half(pt p) {
    return p.y > 0 || (fabs(p.y) < 1e-6 && p.x < 0);
}
double sq(pt p) {return p.x*p.x + p.y*p.y;}
vector<pt> convH(vector<pt> p) {
    int n = p.size();
    if (n <= 3) return p;
    int p0 = 0;
    for(int i = 1; i < n; i++) 
        if (p[i].y > p[p0].y || (fabs(p[i].y-p[p0].y) < 1e-6 && p[i].x > p[p0].x)) p0 = i;
    pt tmp = p[0]; p[0] = p[p0]; p[p0] = tmp;
    pt pivot = p[0];
    sort(++p.begin(),p.end(), [&pivot](pt v, pt w) {
        return make_tuple(half(v-pivot), 0.0, sq(v-pivot)) <
        make_tuple(half(w-pivot), cross(v-pivot,w-pivot), sq(w-pivot));
        });
    vector<pt> s;
    s.push_back(p[n-1]); s.push_back(p[0]); s.push_back(p[1]);

    int i = 2;
    while(i < n) {
        int j = s.size()-1;
        if (orient(s[j-1],s[j],p[i]) > 0) s.push_back(p[i++]);
        else s.pop_back();  
    }
    s.pop_back();
    return s;

}

int main() {
    vector<vector<pt>> polygons;
    int n;
    vector<bool> hit;
    while(cin >> n, n != -1) {
        vector<pt> v(n);
        double xp,yp; 
        for(int i = 0; i < n; i++) {
            cin >> xp >> yp;
            v[i] = {xp,yp};
        }
        polygons.push_back(convH(v));
        hit.push_back(false);
    }

    double ans = 0;
    double xp,yp;
    while(cin >> xp >> yp) {
        pt p = {xp,yp};
        for(int i = 0, n = hit.size(); i < n; i++) {
            if (!hit[i] && inside(polygons[i],p)) {
                ans += areaP(polygons[i]);
                hit[i] = true;
                break;
            }
        }
    }
    cout << setprecision(2) << fixed << ans << "\n";
}