#include <bits/stdc++.h>

using namespace std;

int main() {
    double a,b,c;
    while(1) {
        cin >> a >> b >> c;
        if (a == 0 && b== 0 && c == 0) break;
        vector<double> v = {a,b,c};
        sort(v.begin(),v.end());
        if (fabs(v[2]*v[2] - v[1]*v[1] - v[0]*v[0]) < 1e-6) cout << "right\n";
        else cout << "wrong\n";
    }
}