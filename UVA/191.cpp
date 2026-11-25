#include <bits/stdc++.h>

using namespace std;
typedef complex<int> pt;
#define x real()
#define y imag()

int dot(pt v, pt w) {return (conj(v)*w).x;}
int cross(pt v, pt w) {return (conj(v)*w).y;}

int orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

bool inDisk(pt a, pt b, pt p) {
    return dot(a-p,b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool propInt(pt a, pt b, pt c, pt d) {
    int oa = orient(c,d,a);
    int ob = orient(c,d,b);
    int oc = orient(a,b,c);
    int od = orient(a,b,d);
    if (oa*ob < 0 && oc*od < 0) return true;
    else return false;
}

bool inter(pt a, pt b, pt c, pt d) {
    if (propInt(a,b,c,d)) return true;
    else return (onSegment(a,b,c) || onSegment(a,b,d)
        || onSegment(c,d,a) || onSegment(c,d,b));
}

int main() {
    int n; cin >> n;
    vector<string> answers;
    for(int _ = 0; _ < n; _++) {
        int lx,ly,ex,ey;
        cin >> lx >> ly >> ex >> ey;
        pt ls = {lx,ly}, le = {ex,ey};
        int xleft,ytop,xright,ybottom;
        cin >> xleft >> ytop >> xright >> ybottom;
        if (xleft > xright) swap(xleft,xright);
        if (ybottom > ytop) swap(ybottom,ytop);
        pt leftTop = {xleft,ytop}, leftBottom = {xleft,ybottom};
        pt rightTop = {xright,ytop}, rightBottom = {xright,ybottom};
        vector<pair<pt,pt>> v = {{leftTop,leftBottom},{leftTop,rightTop},
            {leftBottom,rightBottom},{rightTop,rightBottom}};
        bool inters = lx >= xleft && lx <= xright && ly >= ybottom && ly <= ytop;
        for(int i = 0; i < 4; i++) {
            inters |= inter(ls,le,v[i].first,v[i].second);
        }
        if (inters) answers.push_back("T");
        else answers.push_back("F");
    }
    for(int i = 0; i < answers.size(); i++) cout << answers[i] << "\n";
}