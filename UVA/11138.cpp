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
int n,b;
int f = 0;
v<vi> mat;
vi p;

void aug(int u, int mine) {
    int pu = p[u];
    if (u == 0) f = mine;
    else if (pu != -1) {
        aug(pu, 1);
        mat[pu][u] -= f;
        mat[u][pu] += f;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    forn (tt,1,TT+1) {
        cin >> b >> n;
        v<v<pii>> g(n+b+2);
        mat = v<vi>(n+b+2, vi(n+b+2,0));
        forn(i,2,b+2) {
            g[0].pb({1,i});
            g[i].pb({0,0});
            mat[0][i] = 1;
        }
        forn(i,b+2,n+2+b) {
            g[i].pb({1,1});
            g[1].pb({0,i});
            mat[i][1] = 1;
        }
        forn(i,2,b+2) {
            forn(j,b+2,n+b+2) {
                bool fits; cin >> fits;
                if (fits) {
                    g[i].pb({1,j});
                    g[j].pb({0,i});
                    mat[i][j] = 1;
                }
            }
        }
        int mf = 0;

        while(1) {
            f = 0;
            p = vi(n+b+2,-1);
            v<bool> marked(n+b+2,false); marked[0] = true;
            queue<int> q;
            q.push(0);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == 1) break;
                forn(i,0,g[u].size()) {
                    pii v = g[u][i];
                    if (mat[u][v.second] > 0 && !marked[v.second]) {
                        marked[v.second] = true;
                        q.push(v.second);
                        p[v.second] = u;
                    }
                }
            }
            aug(1,500);
            if (f == 0) break;
            mf += f;
        }
        cout << "Case " << tt << ": a maximum of " << mf;
        cout << " nuts and bolts can be fitted together\n";
        
    }
}
