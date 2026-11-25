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

int n,m;

bool has_solution(vector<vector<pii>>& BFG, vector<vector<pii>>& G, int mid) {
    forn(u,0,n) {
        forn(i,0,BFG[u].size()) {
            BFG[u][i].second = G[u][i].second-mid;
        }
    }
    vi changed;
    changed.pb(n); 
    vi dist(n+1,INT32_MAX);
    dist[n] = 0;
    vi iter(n+1,0);
    for(int i = 1; i <= n+1 && !changed.empty();i++) {
        vi ext;
        for(int v : changed) {
            for(pii e : BFG[v]) {
                if (dist[v] + e.second < dist[e.first]) {
                    if (iter[e.first] != i) ext.pb(e.first);
                    iter[e.first] = i;
                    dist[e.first] = dist[v]+e.second;
                }
            }
        }
        swap(ext,changed);
    }
    return changed.empty();
}

bool has_cycle(vector<vector<pii>>& G, int u, vector<int>& mark) {
    bool ans = false;
    forn(i,0,G[u].size()) {
        int v = G[u][i].first;
        if (mark[v] == 0) return true;
        else if (mark[v] == -1) {
            mark[v] = 0;
            ans = ans || has_cycle(G,v,mark);
        }
    }
    mark[u] = 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n) {
        cin >> m;
        vector<vector<pii>> G(n);
        int max_edge = INT_FAST32_MIN;
        forn(i,0,m) {
            int u,v,d;
            cin >> u >> v >> d;

            G[u-1].pb({v-1,d});
            maxeq(max_edge,d);
        }
        vi mark(n,-1);
        bool cycles = false;
        forn(i,0,n) {
            if (mark[i] == -1) {
                mark[i] = 0;
                cycles = cycles || has_cycle(G,i,mark);
            }
        }
        if (!cycles) {
            cout << "Infinite\n";
            continue;
        }
        vector<vector<pii>> BFG(n+1);
        forn(i,0,n) {
            BFG[n].pb({i,0});
        }
        forn(u,0,n) {
            forn(i,0,G[u].size()) {
                BFG[u].pb(G[u][i]);
            }
        }
        int lowb = 0;
        int highb = max_edge+1;
        while(highb-lowb > 1) {
            int mid = (lowb+highb)/2;
            bool can = has_solution(BFG,G,mid);
            if (can) lowb = mid;
            else highb = mid;
            
        }
        if (lowb == 0) cout << "No Solution\n";
        else cout << lowb << "\n";
    }
}
