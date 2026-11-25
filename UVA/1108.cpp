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
int m,n;
v<vi> G;
int n_children;
vi dfs_num;
vi dfs_low;
vi parent;
int dfs_counter;
v<bool> is_ap;

vi marked;
int mark;
void find_ap(int u) {
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    forn(i,0,G[u].size()) {
        int v = G[u][i];
        if (dfs_num[v] == -1) {

            parent[v] = u;
            if (u == 0) n_children++;
            find_ap(v);
            if (dfs_low[v] >= dfs_num[u]) is_ap[u] = true;
            mineq(dfs_low[u],dfs_low[v]);
        } else if (v != parent[u]) {
            mineq(dfs_low[u],dfs_num[v]);
        }
    }
}


pair<bool,int> find_deadends(int u) {
    if (marked[u] == mark) return {true,0};
    else if (is_ap[u] || (marked[u] != -1 && marked[u] != mark)) return {false,0};
    else {
        marked[u] = mark;
        bool has_deadend = true;
        int deadend_nodes = 0;
        forn(i,0,G[u].size()) {
            pair<bool,int> p = find_deadends(G[u][i]);
            has_deadend &= p.first;
            deadend_nodes += p.second;
        }
        return {has_deadend,deadend_nodes+1};
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    while(cin >> m, m) {
        v<pii> edges;
        int maxn = 1;
        int s,t;
        forn(i,0,m) {
            cin >> s >> t;
            maxeq(maxn, max(s,t));
            edges.pb({s-1,t-1});
        }
        n = maxn;
        G = v<vi>(n, vi());
        forn(i,0,m) {
            G[edges[i].first].pb(edges[i].second);
            G[edges[i].second].pb(edges[i].first);
        }

        n_children = 0;
        dfs_num = vi(n,-1);
        dfs_low = vi(n,0);
        parent = vi(n,-1);
        parent[0] = 0;
        dfs_counter = 0;
        is_ap = v<bool>(n,false);

        find_ap(0);
        is_ap[0] = n_children > 1 ;

        int min_num = 0;
        ll num_ways = 1;
        marked = vi(n,-1);
        mark = 0;
        forn(u,0,n) {
            if (is_ap[u]) {
                
                forn(j,0,G[u].size()) {
                    marked[u] = mark;
                    pair<bool,int> p = find_deadends(G[u][j]);
                    if (p.first) {
                        min_num++;
                        num_ways *= (ll) p.second;
                    }
                    mark++;
                }
            }
        }
        cout << "Case " << tt++ << ": ";
        
        if (min_num == 0) cout << "2 " << ((ll) n)*((ll) n-1)/2 << "\n";
        else cout << min_num << " " << num_ways << "\n";
    }
}
