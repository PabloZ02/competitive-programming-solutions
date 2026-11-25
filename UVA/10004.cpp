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
vector<vi> g;
v<int> marked;
bool bip_dfs(int u, int color) {
    marked[u] = color;
    bool ans = true;
    forn(i,0,g[u].size()) {
        int v = g[u][i];
        if (marked[v] == -1) ans &= bip_dfs(v, (color+1)%2);
        else if (marked[v] == color) return false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while(n != 0){
        g = vector<vi>(n, vi({}));
        marked = vector<int>(n,-1);
        int m; cin >> m;
        forn(i,0,m) {
            int a,b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        bip_dfs(0,0) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
        cin >> n;
    }
}
