#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        long long a,b,c;
        cin >> a >> b >> c;
        vector<long long> v = {a,b,c};
        sort(v.begin(),v.end());
        if (v[0] > 0 && v[0]+v[1] > v[2]) cout << "OK\n";
        else cout << "Wrong!!\n";
    }
}