#include <bits/stdc++.h>
using namespace std;
//--------------- MACROS ---------------
// clang-format off
#define ll long long
#define pb push_back
#define mineq(a,n) a = min((a), (n)) 
#define maxeq(a,n) a = max((a), (n))
#define forn(i,a,n) for (int i = (a); i < (n); ++i) 
#define fori(i,a,n) for (int i = (a); i <= (n); ++i) 
#define forb(i,a,n,b) for (int i = (a); i < (n) && (b); ++i) 
#define fors(i,a,n,s) for (int i = (a); i < (n); i+=(s)) 
#define forr(i,n,a) for (int i = (n); i >= (a); --i) 
#define inf INT32_MAX
#define sortv(v) sort(v.begin(), v.end())
#define sortvc(v, comp) sort(v.begin(), v.end(), comp)
#define its(v) v.begin(), v.end()
#define printb(b) cout << ((b) ? "YES" : "NO") << '\n'
#define printl(i) cout << i << '\n'
#define printe(i) cout << i << ' '
#define nl '\n'
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
template <typename T>
using v = vector<T>;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vector<vector<T>>>;
// clang-format on
//--------------------------------------
vector<vector<ll>> M = vector<vector<ll>>(5, vector<ll>(30001,-1));;
vi coins = {1,5,10,25,50};
ll ways(int i, int n) {
    if (n < 0 || i < 0) return 0;
    else if (n == 0) return 1;
    else if (M[i][n] != -1) return M[i][n];
    else {
        M[i][n] = ways(i,n-coins[i]) + ways(i-1,n);
        return M[i][n];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string ns;
    while(getline(cin,ns)) {
        int n = stoi(ns);
        ll ans = ways(4,n);
        if (ans == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
        else cout <<"There are " << ans << " ways to produce " << n << " cents change.\n";
    }
}
