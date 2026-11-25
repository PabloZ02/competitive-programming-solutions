#include <bits/stdc++.h>

using namespace std;

void fail() {
    cout << "-1.000\n";
}

int main() {
    double ma,mb,mc;
    cout << setprecision(3) << fixed;
    double tt = 2.0/3.0;
    for(int _ = 0; _ < 1000; _++) {
        cin >> ma >> mb >> mc;
        if (ma <= 0 || mb <= 0 || mc <= 0) {fail(); continue;}
        double aroot = -(ma*ma) + 2*mb*mb + 2*mc*mc;
        if (aroot < 0) {fail();continue;}
        double broot = -(mb*mb) + 2*ma*ma + 2*mc*mc;
        if (broot < 0) {fail(); continue;}
        double croot = -(mc*mc) + 2*ma*ma + 2*mb*mb;
        if (croot < 0) {fail(); continue;}
        double a = tt*sqrt(aroot), b = tt*sqrt(broot), c = tt*sqrt(croot);
        if (!(a+b > c && a+c > b && b+c>a)) {fail();continue;}
        double s = (a+b+c)/2.0;
        cout << sqrt(s * (s-a) * (s-b) * (s-c)) << "\n";
    }
}