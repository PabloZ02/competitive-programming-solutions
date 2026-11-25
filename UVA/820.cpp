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
v<vi> mat;
int f;
vi p;
int s,t;
void aug(int u, int mine) {
    int pre = p[u];
    if (u == s) f = mine;
    else if (pre != -1) {
        aug(pre, min(mine, mat[pre][u]));
        mat[pre][u] -= f;
        mat[u][pre] += f;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int casen = 1;
    while(n != 0) {
        int m; 
        cin >> s >> t >> m;
        s--;t--;
        mat = v<vi>(n, vi(n,0));
        v<vi> g(n,vi({}));
        int u,v,c;
        forn(i,0,m) {     
            cin >> u >> v >> c;
            u--;v--;
            if (mat[u][v] != 0) {
                mat[u][v] +=c;
                mat[v][u] +=c;
            }
            else if (c > 0) {
                mat[u][v] = c;
                mat[v][u] = c;
                g[u].pb(v);
                g[v].pb(u);
            }
   
        }
        
        int mf = 0;
        while(1) {
            vector<bool> vis(n,false);
            vis[s] = true;
            queue<int> q;
            f = 0;
            p = vi(n,-1);
            q.push(s);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break;
                forn(i,0,g[u].size()) {
                    int v = g[u][i];
                    if (!vis[v] && mat[u][v] > 0) {
                        vis[v] = true;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            aug(t,1000);
            if (f == 0) break;
            mf += f;
        }
        cout << "Network " << casen << "\n";
        casen++;
        cout << "The bandwidth is " <<mf << ".\n\n";

        cin >> n;
    }
}
