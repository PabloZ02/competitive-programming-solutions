#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}

bool cmpProj(pt v, pt p, pt q) {
    return dot(v,p) < dot(v,q);
}

double side(pt v, pt p, double c) {
    return cross(v,p)-c;
}

double dist(pt v, pt p, double c) {
    return abs(side(v,p,c)) / abs(v);
}

double segPoint(pt a, pt b, pt p) {
    pt v = a-b;
    double c = cross(v,b);
    if (cmpProj(v,p,a) && cmpProj(v,b,p)) {
        return dist(v,p,c);
    }
    return min(abs(p-a), abs(p-b));
}

pt perp(pt p) {return {-p.y, p.x};}

double sq(pt p) {return p.x*p.x + p.y*p.y;}

pt proj(pt p,pt v, double c) {return p - perp(v)*side(v,p,c)/sq(v);}

int main() {
    double xm,ym;
    while(cin >> xm >> ym) {
        int n; cin >> n;
        vector<pair<pt,pt>> segments(n);
        double prevx, prevy;
        cin >> prevx >> prevy;
        for(int i = 0; i < n; i++) {
            double xs,ys; cin >> xs >> ys;
            segments[i] = {{prevx,prevy}, {xs,ys}};
            swap(prevx,xs); swap(prevy,ys);
        }
        double min_dist = numeric_limits<double>::max();
        int min_ind = 0;
        for(int i = 0; i < n; i++) {
            double dists = segPoint(segments[i].first,segments[i].second,{xm,ym});
            if (dists < min_dist) {
                min_dist = dists;
                min_ind = i;
            }
        }
        pt minv = segments[min_ind].first - segments[min_ind].second;
        double minc = cross(minv, segments[min_ind].second);
        pt minp;
        if (!cmpProj(minv,{xm,ym},segments[min_ind].first)) {
            minp = segments[min_ind].first;
        } else if (!cmpProj(minv, segments[min_ind].second, {xm,ym})) {
            minp = segments[min_ind].second;
        }
        else minp = proj({xm,ym},minv,minc);
        cout << setprecision(4) << fixed << minp.x << "\n" << minp.y << "\n";
    }
}
