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
int n,m,p;
v<v<double>> G;
v<pair<int,double>> stores;
v<v<double>> M;
double solve(int uind, int bmask) {
    if (M[uind][bmask] == DBL_MIN) {
        double ans = stores[uind].second - G[stores[uind].first][0];
        forn(i,0,p) {
            if (!(bmask & (1 << i))) {
                maxeq(ans,stores[uind].second +  
                    solve(i, bmask | (1 << i)) - G[stores[i].first][stores[uind].first]);
            }
        }
        M[uind][bmask] = ans;
    }
    return M[uind][bmask];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> n >> m;
        G = v<v<double>>(n+1, v<double>(n+1, DBL_MAX));
        int u,v;
        double d;
        forn(i,0,m) {
            cin >> u >> v >> d;
            G[u][v] = min(G[u][v],d);
            G[v][u] = min(G[v][u],d);
        }
        forn(k,0,n+1) {
            forn(i,0,n+1) {
                forn(j,0,n+1) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        cin >> p;
        int sub = 0;
        stores = {};
        forn(i,0,p) {
            cin >> u >> d;
            bool found = false;
            forb(j,0,i,!found) if (stores[j].first == u) {
                stores[j].second += d;
                found = true;
                sub++;
            }
            if (!found) stores.pb({u,d});
        }
        p -= sub;
        M = vector<vector<double>>(p, vector<double>((1 << p) + 1, DBL_MIN));
        double ans = 0;
        forn(i,0,p) maxeq(ans,solve(i,1 << i) - G[stores[i].first][0]);
        if (ans < 0.005) cout << "Don't leave the house\n";
        else cout << "Daniel can save $" << fixed << setprecision(2) << ans << "\n";
    }
}
