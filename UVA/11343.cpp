#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef complex<ll> pt;
#define x real()
#define y imag()
ll dot(pt v, pt w) {return (conj(v)*w).x;}
ll cross(pt v, pt w) {return (conj(v)*w).y;}

ll orient(pt a, pt b, pt c) {
    return cross(b-a,c-a);
}

bool inDisk(pt a, pt b, pt p) {
    return dot(a-p,b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
    return (orient(a,b,p) == 0) && inDisk(a,b,p);
}

bool propInt(pt a, pt b, pt c, pt d) {
    long long oa = orient(c,d,a);
    long long ob = orient(c,d,b);
    long long oc = orient(a,b,c);
    long long od = orient(a,b,d);

    return ((oa*ob < 0) && (oc*od < 0));
}

bool inter(pt a, pt b, pt c, pt d) {
    if (propInt(a,b,c,d)) return true;
    if (onSegment(c,d,a)) return true;
    if (onSegment(c,d,b)) return true;
    if (onSegment(a,b,c)) return true;
    if (onSegment(a,b,d)) return true;
    return false;
}


int main() {
    int TT; cin >> TT;
    for(int _ = 0; _ < TT; _++) {
        int n; cin >> n;
        vector<pair<pt,pt>> segments(n);
        for(int i = 0; i < n; i++) {
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            segments[i] = {{x1,y1}, {x2,y2}};
        }
        ll count = 0;
        for(int i = 0; i < n; i++) {
            bool intersects = false;
            for(int j = 0; j < n && !intersects; j++) 
            if (j != i)
                intersects = inter(segments[i].first, segments[i].second, segments[j].first, segments[j].second);
            count += !intersects;
        }
        cout << count << "\n";
    }
}