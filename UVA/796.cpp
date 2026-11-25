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
v<vi> g;
vi dfslow;
vi dfsnum;
v<pii> ans;
vi dfsp;
int dfs_count;

void dfs(int u) {
    dfslow[u] = dfsnum[u] = dfs_count++;
    forn(i,0,g[u].size()) {
        int v = g[u][i];
        if (dfslow[v] == -1) {
            dfsp[v] = u;
            dfs(v);
            if (dfslow[v] > dfsnum[u]) {
                int a = min(u,v);
                int b = max(u,v);
                ans.pb({a,b});
            }
            mineq(dfslow[u],dfslow[v]);
        } else if (dfsp[u] != v) mineq(dfslow[u],dfsnum[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        int n = stoi(line);
        g = v<vi>(n, vi({}));
        dfslow = vi(n,-1);
        dfsnum = vi(n,-1);
        ans = {};
        dfs_count = 0;
        dfsp = vi(n,-1);
        forn(i,0,n) {
            int u; cin >> u;
            string js; cin >> js;
            js.pop_back();
            js.erase(js.begin());
            int j = stoi(js);
            forn(k,0,j) {
                int v; cin >> v;
                g[u].pb(v);
            }
        }
        if (n > 0) cin.ignore();
        forn(i,0,n) {
            if (dfslow[i] == -1) dfs(i);
        }
        cout << ans.size() << " critical links\n";
        sortv(ans);
        forn(i,0,ans.size()) {
            cout << ans[i].first << " - " << ans[i].second << "\n";
        }
        cout << "\n";


        cin.ignore();
    }
}
