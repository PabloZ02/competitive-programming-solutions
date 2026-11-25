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
v<bool> visited;
v<v<pii>> g;
int goal;
int dfs(int u) {
    if (u == goal) return 0;
    visited[u] = true;
    int ans = -1;
    forn(i,0,g[u].size()) {
        int v = g[u][i].second;
        if (!visited[v]) {
            int vd = dfs(v);
            if (vd != -1) ans = max(vd, g[u][i].first);
        }
    }
    return ans;
}

class dsu {
   public:
    vector<int> p;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    int casen = 1;
    bool passed = false;
    while(n != 0 || m != 0 || q != 0) {
        if (passed) cout << "\n";
        else passed = true;
        cout << "Case #" << casen << "\n";
        casen++;
        
        v<pair<int, pii>> edges;
        forn(i,0,m) {
            int u,v,w;
            cin >> u >> v >> w;
            u--;v--;
            edges.pb({w, {u,v}});
        }
        sortv(edges);
        dsu d(n);
        v<pair<int,pii>> tree;
        forn(i,0,m) {
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            if (d.get(a) != d.get(b)) {
                d.unite(a,b);
                tree.pb(edges[i]);
            }
        }
        g = v<v<pii>>(n, v<pii>({}));
        forn(i,0,tree.size()) {
            int a = tree[i].second.first;
            int b = tree[i].second.second;
            int w = tree[i].first;
            g[a].pb({w,b});
            g[b].pb({w,a});
        }
        forn(ig,0,q) {
            int a,b;
            cin >> a >> b;
            a--;b--;
            goal = b;
            visited = v<bool>(g.size(),false);
            int ans = dfs(a);
            if (ans != -1) cout << ans << "\n";
            else cout << "no path\n";
            
        }
        cin >> n >> m >> q;
    }
}