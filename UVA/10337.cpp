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
int x;
int n;
ll solve(int i, int alt, vector<vector<int>>&winds, vector<vector<ll>>&M) {
    if (alt < 0 || alt > 9) return LONG_LONG_MAX-100;
    else if (i == n && alt == 0) return 0;
    else if (i == n) return LONG_LONG_MAX-100;
    else if (M[i][alt] != -1) return M[i][alt];
    else {
        ll ans = solve(i+1,alt-1,winds,M) + 20;
        mineq(ans,solve(i+1,alt,winds,M) + 30);
        mineq(ans,solve(i+1,alt+1,winds,M) + 60);
        ans -= winds[alt][i];
        mineq(ans,LONG_LONG_MAX-100);
        M[i][alt] = ans;
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> x;
        n = x/100;
        vector<vector<int>>winds(10, vi(n));
        forn(i,0,10) {
            forn(j,0,n) {
                cin >> winds[9-i][j];
            }
        }
        vector<vector<ll>>M(n, v<ll>(10,-1));
        cout << solve(0,0,winds,M) << "\n\n";
    }
}
