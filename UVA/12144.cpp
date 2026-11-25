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

void djikstra(vector<vector<pii>> &G, vi& dist, int s) {
    dist[s] = 0;
    priority_queue<pii, v<pii>, greater<pii>> q;
    q.push({s,0});
    while(!q.empty()) {
        pii p = q.top();
        q.pop();
        int u = p.first; int d = p.second;
        if (d > dist[u]) continue;
        forn(i,0,G[u].size()) {
            p = G[u][i];
            if (dist[u]+p.second < dist[p.first]) {
                dist[p.first] = dist[u]+p.second;
                q.push({p.first,dist[p.first]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;
    while(cin >> n >> m, n != 0) {
        int s,t;
        cin >> s >> t;
        vector<vector<pii>> G(n);
        vector<vector<pii>> B(n);
        vector<vector<pii>> F(n);
        forn(i,0,m) {
            int u,v,p;
            cin >> u >> v >> p;
            G[u].pb({v,p});
            B[v].pb({u,p});
        }
        vi dists(n, INT32_MAX);
        vi distt(n, INT32_MAX);
        djikstra(G,dists,s);
        djikstra(B,distt,t);
        int mindist = dists[t];
        forn(u,0,n) {
            forn(j,0,G[u].size()) {
                int v = G[u][j].first;
                int d = G[u][j].second;
                if (dists[u]+d+distt[v] > mindist) F[u].pb({v,d});
            }
        }
        vi dist(n,INT32_MAX);
        djikstra(F,dist,s);
        if (dist[t] == INT32_MAX) cout << "-1\n";
        else cout << dist[t] << "\n";
    }
}
