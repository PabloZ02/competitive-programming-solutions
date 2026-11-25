#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

pt inter(pt v1, double c1, pt v2, double c2) {
    double d = cross(v1,v2);
    return (v2*c1 - v1*c2) / d;
}

int main() {
    int n; cin >> n;
    while(n--) {
    double l,w,theta; cin >> l >> w >> theta;
    if (theta == 0.0) {
        cout << "1.000\n"; continue;
    }
    theta = theta*M_PI/180.0;
    bool flipped = false;
    double rem = l;
    pt vh = {1,0}, vv = {0,1};
    double ch = cross(vh,{0,w});
    double ans = 0;
    
    while(1) {
        pt ref = inter({cos(theta),sin(theta)}, 0.0, vh, ch);
        if (ref.x < rem) {
            rem -= ref.x;
            ans += abs(ref);
            flipped = !flipped;
        } else {
            pt goal = inter({cos(theta),sin(theta)},0.0,vv,cross(vv, {rem,0.0}));
            ans += abs(goal);
            if (flipped) goal = {goal.x, w - goal.y};
            cout << setprecision(3) << fixed << ans/abs((pt){l,goal.y}) << "\n";
            break;
        }
    }
    }
}