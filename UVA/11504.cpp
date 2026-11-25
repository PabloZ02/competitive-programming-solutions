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
vi dfs_num;
vi dfs_low;
v<bool> visited;
int dfs_c;
v<bool> cclinked;
vi cc;
vi ans;
v<vi> g_from;
void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfs_c++;
    ans.pb(u);
    visited[u] = true;
    forn(i,0,g_from[u].size()) {
        int v = g_from[u][i];
        if (dfs_num[v] == -1) dfs(v);
        if (visited[v]) mineq(dfs_low[u],dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        int ccnum = cclinked.size();
        cclinked.pb(false);
        while(1) {
            int v = ans[ans.size()-1];
            cc[v] = ccnum;
            ans.pop_back();
            visited[v] = false;
            if (v == u) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    int n, m;
    while (TT--) {
        
        cin >> n >> m;
        v<vi> g_to(n, vi({}));
        g_from = v<vi>(n, vi({}));
        dfs_num = vi(n, -1);
        dfs_low = vi(n,-1);
        visited = v<bool>(n,false);
        dfs_c = 0;
        cclinked = {};
        cc = vi(n,-1);
        ans = {};
        forn(i,0,m) {
            int a, b;
            cin >> a >> b;
            a--;b--;
            g_from[a].pb(b);
            g_to[b].pb(a);
        }
        forn(i,0,n) {
            if (dfs_num[i] == -1) dfs(i);
        }
        forn(i,0,n) {
            int ccnum = cc[i];
            forb(j,0,g_to[i].size(), !cclinked[ccnum]) {
                int v = g_to[i][j];
                cclinked[ccnum] = (cc[v] != ccnum);
            }
        }
        int ans = 0;
        forn(i,0,cclinked.size()) ans += !cclinked[i];
        cout << max(int(n>0),ans) << "\n";
    }
}
