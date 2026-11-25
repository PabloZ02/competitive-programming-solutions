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

    int TT;
    cin >> TT;
    while (TT--) {
        int s,n;
        cin >> s >> n;
        v<pair<double,pii>> edges;
        v<pii> loc(n);
        forn(i,0,n) {
            int x,y;
            cin >> x >>y;
            loc[i] = {x,y};
        }
        forn(i,0,n) {
            forn(j,i+1,n) {
                double dist1 = loc[i].first-loc[j].first;
                double dist2 = loc[i].second -loc[j].second;
                double dist = sqrt(dist1*dist1+dist2*dist2);
                edges.pb({dist, {i,j}});
                
            }
        }
        sortv(edges);
        int remaining = n-s;
        dsu d(n);
        double ans = 0.0;
        forb(i,0,edges.size(), remaining>0) {
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            if (d.get(a) != d.get(b)) {
                d.unite(a,b);
                ans = edges[i].first;
                remaining--;
            }
        }
        cout << fixed << setprecision(2) << ans << "\n";
    }
}
