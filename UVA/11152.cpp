#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    double a,b,c; 
    while(cin >> a >> b >> c) {
    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    double redr = area/s;
    double yellowr = (a*b*c) / (4.0*area);
    cout << setprecision(4) << fixed;
    cout << yellowr*yellowr*M_PI - area << " " << area - redr*redr*M_PI << " "
    << redr*redr*M_PI << "\n";
    }
}