#include<bits/stdc++.h>

using namespace std;

int main() {
    double l,w,h,theta;
    ofstream f("out.txt");
    while(cin >> l >> w >> h >> theta) {
        theta =  theta*M_PI/180.0;
        double th = tan(theta)*l;
        if (th <= h) {
            cout << setprecision(3) << fixed << l*w*h - l*w*th/2.0 << " mL\n"; 
        } else {
            double shortl = h/tan(theta);
            double quad = (l-shortl)*w*h;
            cout << setprecision(3) << fixed << l*w*h - quad - shortl*h*w/2.0 << " mL\n";
        }
    }
}