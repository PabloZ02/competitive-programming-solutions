#include<bits/stdc++.h>

using namespace std;
int main() {
    double a,b,c;
    while(cin >> a >> b >> c) {
        double s = (a+b+c)/2.0;
        double area = sqrt(s * (s-a) * (s-b) * (s-c));
        double r = (abs(area) < 1e-6) ? 0 : area/s; 
        cout << "The radius of the round table is: " << setprecision(3) << fixed << r << "\n";
    }
}