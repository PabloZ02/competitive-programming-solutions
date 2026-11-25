#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef complex<ll> pt;
#define x real()
#define y imag()

int main() {
    int n; cin >> n;
    bool passed = false;
    while(n--) {
        if (passed) cout << "\n";
        else passed = true;
        ll xll,yll,xur,yur; cin >> xll >> yll >> xur >> yur;
        pt r1ll = {xll,yll}, r1ur = {xur,yur};
        cin >> xll >> yll >> xur >> yur;
        pt r2ll = {xll,yll}, r2ur = {xur,yur};
        pt rll = {max(r1ll.x,r2ll.x),max(r1ll.y,r2ll.y)};
        pt rur = {min(r1ur.x,r2ur.x), min(r1ur.y,r2ur.y)};
        if (rll == rur || rll.x >= rur.x || rll.y >= rur.y)
            cout << "No Overlap\n";
        else 
            cout << rll.x <<" " << rll.y << " " << rur.x << " " << rur.y << "\n";
    }
}