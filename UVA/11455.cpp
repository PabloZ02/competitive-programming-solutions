#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    while(n--) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        vector<ll> v = {a,b,c,d};
        sort(v.begin(), v.end());
        if (v[0] == 0)
            cout << "banana\n";
        else if (v[0] == v[3])
            cout << "square\n";
        else if (v[0] == v[1] && v[2] == v[3])
            cout << "rectangle\n";
        else if (v[0]+v[1]+v[2] > v[3])
            cout << "quadrangle\n";
        else 
            cout << "banana\n";
    }
}