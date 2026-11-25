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

void djikstra(v<v<pair<ll,int>>>& g, v<ll>& dist, int s) {
    priority_queue<pair<ll,int>, v<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty()) {
        pair<ll,int> nextq = pq.top();
        pq.pop();
        ll d = nextq.first;
        if (d > dist[nextq.second]) continue;
        forn(i,0,g[nextq.second].size()) {
            pair<ll,int> v = g[nextq.second][i];
            if (v.first+d < dist[v.second]) {
                dist[v.second] = v.first+d;
                pq.push({v.first+d,v.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        int n,m,s,t,p;
        cin >> n >> m >> s >> t >> p;
        v<v<pair<ll,int>>> g(n);
        v<v<pair<ll,int>>> g_from(n);
        forn(i,0,m) {
            int u,v,c;
            cin >> u >> v >> c;
            u--;v--;
            g[u].pb({c,v});
            g_from[v].pb({c,u});
        }
        s--;t--;
        v<ll> dists(n,LLONG_MAX);
        v<ll> distt(n,LLONG_MAX);
        djikstra(g,dists,s);
        djikstra(g_from,distt,t);
        ll max_toll = -1;
        forn(i,0,n) {
            forn(j,0,g[i].size()) {
                pair<ll,int> v = g[i][j];
                if (dists[i] != LLONG_MAX && distt[v.second] != LLONG_MAX) {
                    if (dists[i] + v.first + distt[v.second] <= p) maxeq(max_toll,v.first);
                }
            }
        }
        cout << max_toll << "\n";
    }
}
