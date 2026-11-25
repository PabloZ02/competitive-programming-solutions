#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

int main() {
    int n; double a;
    while(cin >> n >> a, n != 0) {
        vector<pt> corners = {{0,0}, {a,0}, {0,a}, {a,a}};
        double count = 0;
        for(int _ = 0; _ < n; _++) {
            double x,y; cin >> x >> y;
            pt p = {x,y};
            bool inside = true;
            for(int i = 0; i < 4; i++) {
                inside &= abs(corners[i]-p) <= a;
            }
            count += inside;
        }   
        cout << fixed << setprecision(5) << count*a*a / (double)(n) << "\n";
    }
}