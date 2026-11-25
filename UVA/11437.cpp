#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

pt inter(pt v1, double c1, pt v2, double c2) {
    double d = cross(v1,v2);
    return (c1*v2-c2*v1)/d;
}

int main() {
    int n; cin >> n;
    while(n--) {
        double ax,ay,bx,by,cx,cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        pt a = {ax,ay}, b = {bx,by}, c = {cx,cy};
        pt d = b/3.0 + 2.0*c/3.0;
        pt e = c/3.0 + 2.0*a/3.0;
        pt f = a/3.0 + 2.0*b/3.0;

        pt vda = a-d;
        double cda = cross(vda,d);
        pt veb = b-e;
        double ceb = cross(veb,e);
        pt vfc = f-c;
        double cfc = cross(vfc,f);
        pt r = inter(vfc,cfc,vda,cda);
        pt q = inter(vfc,cfc,veb,ceb);
        pt p = inter(vda,cda,veb,ceb);
        cout << (int) round(abs(cross(r-p,q-p))/2.0) << "\n";
    }
}