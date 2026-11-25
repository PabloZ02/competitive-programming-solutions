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

class dsu {
   public:
    vector<int> p;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;
    cin >> n >> m;
    while(n != 0) {
        vector<pair<int, pii>> edges;
        forn(i,0,m) {
            int u,v,w;
            cin >> u >> v >> w;
            edges.pb({w, {u,v}});
        }
        sortv(edges);
        dsu d(n);
        bool passed = false;
        forn(i,0,m) {
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            if (d.get(a) != d.get(b)) {
                d.unite(a,b);
            } else {
                if (passed) cout << " ";
                else passed = true;
                cout << edges[i].first;
            }
        }
        if (passed) cout << "\n";
        else cout << "forest\n";

        cin >> n >> m;
    }
}
