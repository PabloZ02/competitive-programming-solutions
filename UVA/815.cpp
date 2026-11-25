#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    int tt  = 1;
    while(cin >> n >> m, (n != 0 || m != 0)) {
        n = n*m;
        cout << "Region " << tt++ << "\n";
        vector<double> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        double flood; cin >> flood;
         if (flood <= 0.0) {
            cout << setprecision(2) << fixed;
            cout << "Water level is " << v[0] << " meters.\n";
            cout << "0.00 percent of the region is underwater.\n\n";
            continue;
        }
       
        double level = v[0]; int count = 1;
        for(int i = 1; i < n && flood > 1e-6; i++) {
            double dif = v[i] - level;
            double vol = 100.0 * count * dif;
            if (vol < flood) {
                count++;
                flood -= vol;
                level = v[i];
            } else {
                level  += flood / (100.0 * count);
                flood = 0.0;
            }
        }
        if (flood > 1e-6) {
            level  += flood / (100.0 * count);
        }
        cout << setprecision(2) << fixed << "Water level is " << level << " meters.\n";
        cout << 100.0*((double)count)/((double)n) << " percent of the region is under water.\n\n";
    }
}