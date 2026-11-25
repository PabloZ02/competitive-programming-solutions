#include<bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;
    ofstream f("out.txt");
    for(int t = 1; t <= tt; t++) {
        int n; cin >> n;
        vector<long double> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        long double best = 0.0;
        for(int i = 0; i < n-2; i++) {
            if (v[i+2] + v[i+1] > v[i]) {
                long double s = (v[i]+v[i+1]+v[i+2])/2.0;
                best = max(best, sqrt(s*(s-v[i])*(s-v[i+1])*(s-v[i+2])));
            }
        }
        cout << setprecision(2) << fixed << best << "\n";
    }
}