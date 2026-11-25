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
vi dist;
vector<bool> marked;
vi nextv;
int dfs(int u) {
    marked[u] = true;
    int v = nextv[u];
    if (!marked[v]) {
        int ans = dfs(v);
        if (dist[u] == 0) dist[u] = ans+1;
    } else {
        if (dist[v] != 0) dist[u] = dist[v]+1;
        else {
            int reach = 1;
            int k = v;
            while(k != u) {
                k = nextv[k];
                reach++;
            }
            k = v;
            do {
                dist[k] = reach;
                k = nextv[k];
            } while(k != v);
            
        }
    }
    return dist[u];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    forn(t,1,TT+1) {
        int n; cin >> n;
        nextv.resize(n);
        forn(i, 0, n) {
            int from,to;
            cin >> from >> to;
            nextv[from-1] = to-1;
        }
        marked = vector<bool>(n,false);
        dist = vi(n,0);
        int maxind = 0;
        int maxval = dfs(maxind);
        forn(i,1,n) {
            if (!marked[i]) {
                int ndfs = dfs(i);
                if (ndfs > maxval) {
                    maxind = i;
                    maxval = ndfs; 
                }
            }
        }
        cout << "Case " << t << ": ";
        cout << maxind+1 << "\n";
    }
}
