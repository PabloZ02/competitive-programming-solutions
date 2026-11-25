#include <bits/stdc++.h>

using namespace std;
double PI = acos(-1);
int main() {
    int t; cin >> t;
    for(int _ = 0; _ < t; _++) {
        double l; cin >> l;
        double w = l*0.6;
        double r = l*0.2;
        double red = PI*r*r;
        double green = w*l - red;
        cout << setprecision(2) << fixed << red << " " << green << "\n";
    }
}