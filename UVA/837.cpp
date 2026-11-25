#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;

int main() {
    int n; cin >> n;
    for(int ig = 0; ig < n; ig++) {
        if (ig != 0) cout << "\n";
        int ns; cin >> ns;
        vector<pair<double,double>> films(2*ns);
        for(int i = 0; i < ns; i++) {
            double x1,y1,x2,y2,r;
            cin >> x1 >> y1 >> x2 >> y2 >> r;
            if (x1 > x2) swap(x1,x2);
            films[i] = {x1,r};
            films[i+ns] = {x2,1.0/r};
        }
        sort(films.begin(),films.end());
        double coeff = 1.0;
        cout << 2*ns+1 << "\n";
        cout << "-inf " << setprecision(3) << fixed << films[0].first << " " << coeff << "\n";
        for(int i = 0; i < 2*ns-1; i++) {
            coeff *= films[i].second;
            cout << setprecision(3) << fixed << films[i].first << " "
                << films[i+1].first << " " << coeff << "\n"; 
        }
        cout << setprecision(3) << fixed << films[2*ns-1].first << " +inf 1.000\n";
    }
}