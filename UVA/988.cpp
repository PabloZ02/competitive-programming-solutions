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

vi topov;
v<bool> visited;
v<vi> g;
void dfs(int u) {
    visited[u] = true;
    forn(i,0,g[u].size()) {
        int v = g[u][i];
        if (!visited[v]) dfs(v);
    }
    topov.pb(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string ns;
    bool passed = false;
    while(getline(cin,ns)) {
        if (passed) cout << "\n";
        else passed = true;
        int n = stoi(ns);
        g = v<vi>(n,vi());
        forn(i,0,n) {
            int m; cin >> m;
            forn(j,0,m) {
                int v; cin >> v;
                g[i].pb(v);
            }
        }
        topov = {};
        visited = v<bool>(n,false);
        dfs(0);
        vi paths(n,0);
        paths[0] = 1;
        forr(i,n-1,0) {
            int u = topov[i];
            forn(j,0,g[u].size()) {
                paths[g[u][j]] += paths[u];
            }
        }
        int ans = 0;
        forn(i,0,n) {
            if (g[i].empty()) ans+= paths[i];
        }
        cout << ans << "\n";
        cin.ignore();
        cin.ignore();
    }
}
