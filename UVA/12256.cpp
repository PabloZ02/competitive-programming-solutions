#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    vector<ll> rods(61);
    rods[0] = 1; rods[1] = 1; rods[2] = 1;
    for(int i = 3; i < 61; i++)
        rods[i] = rods[i-3]+rods[i-2]+rods[i-1];
    
    ll tt = 1;
    int n; 
    while(cin >> n, n!= 0) 
        cout << "Case " << tt++ << ": " << rods[n-1] << "\n";
}