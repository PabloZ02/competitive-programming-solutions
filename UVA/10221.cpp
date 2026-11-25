#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

int main() {
    double s,a;
    while(cin >> s) {
        cin >> a;
        string mode; cin >> mode;
        if (mode == "min") {
            a /= 60.0;
        }
        a = fmod(a,360);
        if (360-a < a) a = 360-a;
        s += 6440;
        double theta = (a*2*M_PI) / 360.0;
        cout << setprecision(6) << fixed << theta*s << " " << sqrt(2*s*s*(1-cos(theta))) << "\n";
    }
}