#include<bits/stdc++.h>

using namespace std;
double PI = 2*acos(0);
int main() {
    int n; cin >> n; cin.ignore();
    for(int _ = 0; _ < n; _++) {
        string line; getline(cin,line);
        if (line.find(' ') != string::npos) {
            double r1,r2;
            stringstream sstr(line);
            sstr >> r1 >> r2;
            double r = (2*r1 + 2*r2)/2;
            cout << fixed << setprecision(4) << PI*r*r - PI*r1*r1 - PI*r2*r2 << "\n";
        } else {
            double t = stod(line);
            double r = t/4.0;
            cout << fixed << setprecision(4) << PI*(t/2.0)*(t/2.0) - 2*PI*r*r << "\n";
        }
    }
}