#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

double area(pt a, pt b, pt c) {return abs(cross(b-a,c-a))/2.0;}

pt inter(pt v1, pt v2, double c1, double c2) {
    double d = cross(v1,v2);
    return (v2*c1 - v1*c2) / d;
}

string symbol(double d) {
    if (d >= 0) return "-";
    else return "+";
}

int main() {
    double ax,ay,bx,by,cx,cy;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy) {
        pt a = {ax,ay}, b = {bx,by}, c = {cx,cy};
        double r = abs(a-b)*abs(a-c)*abs(b-c) / (4.0 * area(a,b,c));
        pt ab = b-a;
        pt ab_center = (a+b)/2.0;
        pt v_ab = {ab.y,-ab.x};
        double c_ab = cross(v_ab,ab_center);

        pt ac = c-a;
        pt ac_center = (a+c)/2.0;
        pt v_ac = {ac.y,-ac.x};
        double c_ac = cross(v_ac,ac_center);

        pt center = inter(v_ab,v_ac,c_ab,c_ac);
        
        cout << setprecision(3) << fixed;
        cout << "(x " << symbol(center.x) << " " << abs(center.x) << ")^2 + ";
        cout << "(y " << symbol(center.y) << " " << abs(center.y) << ")^2 = ";
        cout << abs(r) << "^2\n";

        double xcoef = 2*center.x, ycoef = 2*center.y;
        double e = -(center.x*center.x + center.y*center.y - r*r);

        cout << "x^2 + y^2 " << symbol(xcoef) << " " << abs(xcoef) << "x ";
        cout << symbol(ycoef) << " " << abs(ycoef) << "y ";
        cout << symbol(e) << " " << abs(e) << " = 0\n";

        cout << "\n";

    }
}