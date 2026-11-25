#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()


bool circle2PtsRad(pt p1, pt p2, double r, pt &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c = {(p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h,
            (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h};
return true; 
}

int main() {
    int n; 
    while(cin >> n, n) {
        vector<pt> points(n);
        for(int i = 0; i < n; i++) {
            double xp,yp; cin >> xp >> yp;
            points[i] = {xp,yp};
        }
        double r; cin >> r;
        bool won = false;
        for(int i = 0; i < n && !won; i++)
        for(int j = i+1; j < n && !won; j++) {
            pt c1,c2;
            circle2PtsRad(points[i],points[j],r,c1);
            won = true;
            for(int k = 0; k < n; k++) {
                if (abs(points[k]-c1) > r) {
                    won = false; break;
                }
            }
            if (won) break;
            circle2PtsRad(points[j],points[i],r,c2);
            won = true;
            for(int k = 0; k < n; k++) {
                if (abs(points[k]-c2) > r) {
                    won = false; break;
                }
            }
        }
        if (won) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }
}