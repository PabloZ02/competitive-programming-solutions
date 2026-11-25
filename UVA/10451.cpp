#include<bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

double PI = 2*acos(0);

int main() {
    int n;double a; int tt = 1;
    while(cin >> n, n >= 3) {
        cin >> a;
        double theta = 2*PI/n;
        double bh = a*2/n;
        double h = sqrt(a/(n*tan(PI/n)));
        double b = bh/h;
        double r = b/(2*sin(theta/2));
        cout << "Case " << tt++ << ": ";
        cout << setprecision(5) << fixed << PI*r*r - a << " "
            << a-PI*h*h << "\n";
    }
}