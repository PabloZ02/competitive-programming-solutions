#include <bits/stdc++.h>

using namespace std;
typedef complex<int> pt;
#define x real()
#define y imag()

int signComp(int a, int b) {
    if (a < b) return -1;
    else return a > b;
}

int main() {
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;
        vector<pt> brownies(n);
        for(int i = 0; i < n; i++) {
            int xb,yb; cin >> xb >> yb;
            brownies[i] = {xb,yb};
        }
        pt div = brownies[n/2];
        int sp = 0, op = 0;
        for(int i = 0; i < n; i++) {
            int p = signComp(div.x,brownies[i].x) * signComp(div.y,brownies[i].y);
            if (p == 1) sp++;
            else op -= p;
        }
        cout << sp << " " << op << "\n";
    }
}