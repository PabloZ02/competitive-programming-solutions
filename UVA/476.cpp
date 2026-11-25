#include <bits/stdc++.h>

using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
    char c;
    vector<pair<pt,pt>> r;
    while(cin >> c, c != '*') {
        double xb,yb,xe,ye; cin >> xb >> yb >> xe >> ye;
        r.push_back({{xb,yb},{xe,ye}});
    }
    double xp,yp;
    int ptn = 1;
    while(cin >> xp >> yp, (xp != 9999.9 || yp != 9999.9)) {
        pt p = {xp,yp};
        bool contained = false;
        for(int i = 0; i < r.size(); i++)
        if (xp > r[i].first.x && xp < r[i].second.x)
        if (yp < r[i].first.y && yp > r[i].second.y) {
            contained = true;
            cout << "Point " << ptn << " is contained in figure " << i+1 << "\n";
        }
        if (!contained)
            cout << "Point " << ptn << " is not contained in any figure\n";
        ptn++;
    }
}