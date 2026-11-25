#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(cin >> n, n != 0) {
        int bi = 0; double bs = 0;
        for(int i = 0; i < n; i++) {
            double x,y; cin >> x >> y;
            double side = max(min(x/2.,y/2.),max(min(x/4.,y),min(x,y/4.)));
            if (side > bs) {
                bs = side;
                bi = i;
            }
        }
        cout << bi+1 << "\n";

    }
}