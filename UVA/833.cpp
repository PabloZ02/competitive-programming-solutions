#include <bits/stdc++.h>

using namespace std;
typedef complex<int> pt;
#define x real()
#define y imag()

struct line{
    pt v; int c;
};
int dot (pt v, pt w) {return (conj(v)*w).x;}
int cross(pt v, pt w) {return (conj(v)*w).y;}

int orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

bool cmpProj(pt p, pt q, line l) {
    return dot(l.v,p) < dot(l.v,q);
}

int side(line l, pt p) {
    return cross(l.v,p)-l.c;
}

double dist(line l, pt p) {
    return abs(side(l,p)) / abs(l.v);
}

double segDist(pt a, pt b, pt p) {
    pt v1 = a-b;
    line l = {v1,cross(v1,p)};
    if (cmpProj(a,p,l) && cmpProj(b,p,l)) return dist(l,p);
    return min(abs(p-a), abs(p-b));
}

int main() {
    int n; cin >> n;
    for(int ig = 0; ig < n; ig++) {
        if (ig != 0) cout << "\n";
        int np; cin >> np;
        vector<pair<pt,pt>> segments(np);
        for(int i = 0; i <np; i++) {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) {
                swap(x1,x2); swap(y1,y2);
            }
            segments[i] = {{x1,y1}, {x2,y2}};
        }
        int ns; cin >> ns;
        for(int _ = 0; _ < ns; _++) {
            int cur_x, cur_y; cin >> cur_x >>cur_y;
            while(1) {
                double min_dist = numeric_limits<double>::max();
                int chosen_index = -1;
                pt p = {cur_x,cur_y};
                for(int i = 0; i < segments.size(); i++) {
                    if (orient(segments[i].first,segments[i].second,p) > 0)
                    if (p.x >= segments[i].first.x && p.x <= segments[i].second.x) {
                        double d = segDist(segments[i].first,segments[i].second,p);
                        if (d < min_dist) {
                            min_dist = d; chosen_index = i;
                        }
                    }
                }
                if (chosen_index == -1) break;
                if(segments[chosen_index].first.y < segments[chosen_index].second.y) {
                    cur_x = segments[chosen_index].first.x;
                    cur_y = segments[chosen_index].first.y;
                } else {
                    cur_x = segments[chosen_index].second.x;
                    cur_y = segments[chosen_index].second.y;
                }
            }
            cout << cur_x << "\n";
        }
    }
}