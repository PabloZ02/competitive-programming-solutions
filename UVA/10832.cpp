#include <bits/stdc++.h>

using namespace std;
struct pt {
    int x,y,z;
};

double dist(pt v, pt w) {
    double d1 = v.x-w.x;
    double d2 = v.y-w.y;
    double d3 = v.z-w.z;
    return sqrt(d1*d1 + d2*d2 + d3*d3);
}

int main() {
    double f,b,r; int n;
    int mission = 1;
    while(1) {
        cin >> f >> b >> r >> n;
        if (f == 0 || b == 0 || r == 0 || n == 0) break;
        vector<pair<pt,bool>> buoys(n);
        for(int i = 0; i < n; i++) {
            int x,y,z; cin >> x >> y >> z;
            buoys[i] = {{x,y,z}, true};
        }
        bool failed = false;
        pt cur = {0,0,1};
        double time = 0, travelled = 0;
        double fail_distance = 0;
        for(int i = 0; i < n; i++) {
            int closest = -1;
            double min_dist = numeric_limits<double>::max();
            for(int j = 0; j < n; j++) {
                if (!buoys[j].second) continue;
                double d = dist(cur,buoys[j].first);
                if (d < min_dist) {
                    min_dist = d;
                    closest = j;
                }
            }
            buoys[closest].second = false;
            cur = buoys[closest].first;

            double lap_time = min_dist/r;
            time += lap_time;
            if (!failed && f - b*lap_time < 0) {
                failed = true;
                double fail_time = f/b;
                fail_distance = travelled + fail_time*r;
            }
            f -= b*lap_time;
            travelled += lap_time*r;

        }
        cout << setprecision(2) << fixed;
        if (!failed) {
            cout << "Mission " << mission++ << ": SUCCESS!! Time: " << time << "  ";
            cout << "Traveled: " << travelled << "  Fuel Left: " << f << "\n";
        } else {
            cout << "Mission " << mission++ << ": FAILURE!! Traveled: ";
            cout << fail_distance << "  From Home: " << travelled-fail_distance << "\n";
        }
    }
}