#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}

int main() {
    double xa,ya,xb,yb,xc,yc,xd,yd,xe,ye,xf,yf;
    while(1) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd >> xe >> ye >> xf >> yf;
        if (!(xa != 0 || xb != 0 || xc != 0 || xd != 0 || xe != 0 || xf != 0 || 
        ya != 0 || yb != 0 || yc != 0 || yd != 0 || ye != 0 || yf != 0)) break;
        pt d = {xd,yd}, e = {xe,ye}, f = {xf,yf};
        double area = abs(cross(e-d,f-d)) / 2.0;
        pt a = {xa,ya}, b = {xb,yb}, c = {xc,yc};
        double sint = cross(b-a,c-a) / (abs(b-a)*abs(c-a));
        double len = abs(area / (abs(b-a)*sint));
        
        
        
        //double len =  area / hypot(xa-xb,ya-yb);

        pt v = c-a; v /= abs(v);
        pt h = a + len*v;
        pt g = (h-a) + b;
        cout << setprecision(3) << fixed << g.x << " " << g.y << " " 
            << h.x << " " << h.y << "\n";
    }
}