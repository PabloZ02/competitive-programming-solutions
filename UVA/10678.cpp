#include<bits/stdc++.h>

using namespace std;
double PI = 2*acos(0);
int main() {
    int n; cin >> n;
    cout << setprecision(3) << fixed;
    for(int _ = 0; _ < n; _++) {
        double d,r; cin >> d >> r;
        double a = r/2.0;
        double base = d/2.0;
        double h = r/2.0;
        double b = sqrt(h*h - base*base);
        cout << a*b*PI << "\n";
    }
}