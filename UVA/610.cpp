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
v<vi>G;
int dfscounter;
vi dfs_low;
vi dfs_num;
set<pii> edges;
vi parent;
void find_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfscounter++;
    forn(i,0,G[u].size()) {
        int v = G[u][i];
        if (dfs_num[v] == -1) {
            parent[v] = u;
            find_bridges(v);
            if (dfs_low[v] > dfs_num[u]) {
                edges.insert({u,v});
                edges.insert({v,u});
            } else {
                edges.insert({u,v});
            }
            mineq(dfs_low[u],dfs_low[v]);
        } else if (v != parent[u]) {
            if (dfs_low[u] >= dfs_num[v]) {
                edges.insert({u,v});
                dfs_low[u] = dfs_num[v];
            } else if (edges.count({v,u}) == 0) edges.insert({u,v});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    int n,m;
    while(cin >> n >> m,n) {
        G = v<vi>(n, vi());
        forn(i,0,m) {
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfscounter = 0;
        dfs_low = vi(n,0);
        dfs_num = vi(n,-1);
        edges = {};
        parent = vi(n,-1);
        parent[0] = 0;
        cout << tt++ << "\n\n";
        forn(i,0,n) if (dfs_num[i] == -1) find_bridges(i);
        
        for(auto e : edges) {
            cout << e.first+1 << " " << e.second+1 << "\n";
        }
        cout << "#\n";
        
    }
}
