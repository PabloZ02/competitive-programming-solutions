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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int casen = 1;
    int a,b;
    cin >> a >> b;
    while(a != 0) {
        int ind = 2;
        vi int2ind(101,-1);
        v<vi> g;
        int2ind[a] = 0;
        int2ind[b] = 1;
        g.pb({1});
        g.pb({});
        cin >> a >> b;
        while(a != 0) {       
            if (int2ind[a] == -1) {
                int2ind[a] = ind;
                ind++;
                g.pb({});
            }
            if (int2ind[b] == -1) {
                int2ind[b] = ind;
                ind++;
                g.pb({});
            }
            g[int2ind[a]].pb(int2ind[b]);
            cin >> a >> b;
        }
        int n = ind;
        v<v<ll>> mat(n,v<ll>(n,INT32_MAX));
        forn(i,0,n) {
            forn(j,0,g[i].size()) {
                int v = g[i][j];
                mat[i][v] = 1;
            }
        }
        
        forn(k,0,n) {
            forn(i,0,n) {
                forn(j,0,n) {
                    mineq(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        ll avg = 0;
        forn(i,0,n) {
            forn(j,0,n) {
                if (i != j) avg += mat[i][j];
            }
        }
        double ans = double(avg)/double(n*(n-1));
        cout << "Case " << casen << ": average length between pages = ";
        casen++;
        cout << fixed << setprecision(3) << ans << " clicks\n";
        cin >> a >> b;
    }
}
