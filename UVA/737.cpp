#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct point {
    ll x,y,z;
};

int main() {
    int n;
    while(cin >> n, n) {
        ll x,y,z,d; cin >> x >> y >> z >> d; n--;
        pair<point,point> cube = {{x,y,z},{x+d,y+d,z+d}};
        while(n--) {
            cin >> x >> y >> z >> d;
            point cl = cube.first, cu = cube.second;
            cube = {{max(cl.x,x),max(cl.y,y),max(cl.z,z)}, 
                {min(cu.x,x+d),min(cu.y,y+d),min(cu.z,z+d)}};
        }
        point cl = cube.first, cu = cube.second;
        if (cl.x >= cu.x || cl.y >= cu.y || cl.z >= cu.z) cout << "0\n";
        else cout << (cu.x-cl.x)*(cu.y-cl.y)*(cu.z-cl.z)  << "\n";
    }
}