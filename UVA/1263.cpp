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

bool inside_coord(int ci, int cj, int di) {
    return (ci <= cj+di) && (ci >= cj-di);
}

v<vi> G;
v<vi> B;
vi comps;


void kos(v<vi>& graph, vi& order, int u, int c) {
    if (comps[u] >= 0) return;
    comps[u] = c;
    forn(i,0,graph[u].size()) kos(graph,order,graph[u][i],c);
    order.pb(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        int n; cin >> n;
        v<pair<pii,int>> vec(n);
        int x,y,d;
        forn(i, 0, n) {
            cin >> x >> y >> d;
            vec[i] = {{x,y},d};
        }
        G = v<vi>(n, vi());
        B = v<vi>(n, vi());
        forn(i,0,n) {
            pii xyi = vec[i].first;
            int di = vec[i].second;
            forn(j,i+1,n) {    
                pii xyj = vec[j].first;
                int dj = vec[j].second;
                if (inside_coord(xyj.first,xyi.first,di/2) && inside_coord(xyj.second,xyi.second,di/2)) {
                    G[i].pb(j);
                    B[j].pb(i);
                }
                if (inside_coord(xyi.first,xyj.first,dj/2) && inside_coord(xyi.second,xyj.second,dj/2)) {
                    G[j].pb(i);
                    B[i].pb(j);
                }
            }
        }
        /*cout << "edges:\n";
        forn(i,0,n) {
            forn(j,0,G[i].size()) {
                cout << i << " " << G[i][j] << "\n"; 
            }
        }*/
        comps = vi(n,-1);
        vi order(n,-1);
        iota(order.begin(),order.end(),0);
        vi dfs_order;
        forr(i,n-1,0) {
            kos(G,dfs_order,order[i],order[i]);
        }
        comps = vi(n,-1);
        forr(i,n-1,0) {
            kos(B,dfs_order,dfs_order[i],dfs_order[i]);
        }
        vector<bool> start(n,false);
        forn(i,0,n) start[comps[i]] = true;
        forn(i,0,n) {
            forn(j,0,G[i].size()) {
                if (comps[i] != comps[G[i][j]]) start[comps[G[i][j]]] = false;
            }
        }
        int count = 0;
        forn(i,0,n) count += start[i];
        cout << count << "\n";
        //forn(i,0,n) cout << i << " " << comps[i] << "\n";
    }
}
