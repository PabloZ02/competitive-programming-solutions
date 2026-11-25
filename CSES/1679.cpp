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
vi marked;
v<vi> G;
vi topo_list;

bool toposort(int u) {
    if (marked[u] == 0) return false;
    else if (marked[u] == 1) return true;
    else {
        marked[u] = 0;
        forn(i,0,G[u].size()) {
            if (!toposort(G[u][i])) return false;
        }
        topo_list.pb(u);
        marked[u] = 1;
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;
    cin >> n >> m;
    marked = vi(n,-1);
    G = v<vi>(n, vi());
    int u,v;
    forn(i,0,m) {
        cin >> u >> v;
        G[v-1].pb(u-1);
    }
    bool is_dag = true;
    forb(i,0,n,is_dag) {
        if (marked[i] == -1) {
            is_dag = toposort(i);
        }
    }
    if (!is_dag) cout << "IMPOSSIBLE\n";
    else {
        cout << topo_list[0]+1;
        forn(i,1,n) cout << " " << topo_list[i]+1;
        cout << "\n";
    }
}
