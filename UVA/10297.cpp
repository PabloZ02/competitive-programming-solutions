#include <bits/stdc++.h>

using namespace std;

int main( ){
    double d,v;
    while(cin >> d >> v, (d != 0. || v != 0.)) {
        double r = d/2.0;
        double or_v = r*r * M_PI * d;
        double rem_v = or_v - v;
        double ans = cbrt(12.0/(16.0*M_PI)*(rem_v - M_PI*d*d*d/12.0));
        cout << setprecision(3) << fixed << 2.0*ans << "\n";
    }
}