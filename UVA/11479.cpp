#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    for(int tt = 1; tt <= n; tt++) {
        int a,b,c; cin>> a >> b >> c;
        vector<long long> t = {a,b,c};
        sort(t.begin(),t.end());
        cout << "Case " << tt << ": ";
        if (t[0]+t[1] <= t[2] || t[0] <= 0) {
            cout << "Invalid\n";
        } else if (t[0] == t[2])
            cout << "Equilateral\n";
        else if (t[0] == t[1] || t[1] == t[2])
            cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}