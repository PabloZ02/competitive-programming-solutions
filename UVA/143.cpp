#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()
double EPS = 1e-6;
double dot(pt v, pt w) {return (conj(v)*w).x;}
double cross(pt v, pt w) {return (conj(v)*w).y;}
bool inDisk(pt a, pt b, pt p) {
    return dot(a-p,b-p) <= EPS;
}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

int sign(double d) {
    if (d > EPS) return 1;
    else if (d < -EPS) return -1;
    else return 0;
}
bool inside_t(pt p, pt a, pt b, pt c) {
    int orientation = sign(orient(a,b,c));
    int o1 = sign(orient(a,b,p)), o2 = sign(orient(b,c,p)), o3 = sign(orient(c,a,p));
    if (orientation == 0) {
        if (!(o1 == 0 && o2 == 0 && o3 == 0)) return false;
        if (a == b && b == c) return p == a;
        else {
            pt p1, p2;
            double dab = abs(a-b), dac = abs(a-c), dbc = abs(b-c);
            if (dab > dac && dab > dbc) {p1 = a; p2 = b;}
            else if (dac > dbc) {p1 = a; p2 = c;}
            else {p1 = b; p2 = c;}
            return inDisk(p1,p2,p);
        }
    }
    return !(o1 == -orientation || o2 == -orientation || o3 == -orientation);
}
int main() {
    vector<pt> points(3);
    while(1) {
        int zeros = 0;
        for(int i = 0; i < 3; i++) {
            double a,b; cin >> a >> b;
            zeros += a == 0 && b == 0;
            points[i] = {a,b};
        }
        if (zeros == 3) break;
        int count = 0;
        for(int i = 1; i < 100; i++)
        for(int j = 1; j < 100; j++)
            count += inside_t({i,j},points[0],points[1],points[2]);
        cout << setw(4)  <<  right << count << "\n";
    }
}