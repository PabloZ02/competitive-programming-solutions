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
    forn(tt,1,TT+1) {
        cout << "Case #" << tt << ": ";
        int n, r;
        cin >> n >> r;
        v<pii> vp(n);
        forn(i,0,n) {
            int a,b;
            cin >> a >> b;
            vp[i] = {a,b};
        }
        v<pair<double, pii>> edges;
        forn(i,0,n) {
            pii p1 = vp[i];
            forn(j,i+1,n) {
                pii p2 = vp[j];
                double dista = (p1.first-p2.first);
                double distb = (p1.second-p2.second);
                double dist = sqrt(dista*dista+distb*distb);
                edges.pb({dist, {i,j}});
            }
        }
        sortv(edges);
        double road = 0.0;
        double railroad = 0.0;
        int states = 1;
        dsu d(n);
        forn(i,0,edges.size()) {
            pair<double, pii> nexte = edges[i];
            if (d.get(nexte.second.first) != d.get(nexte.second.second)) {
                d.unite(nexte.second.first, nexte.second.second);
                if (nexte.first > r) {
                    states++;
                    railroad += nexte.first;
                }  else {
                    road += nexte.first;
                }
            }
        }
        cout << states << " " << round(road) << " " << round(railroad) << "\n";

    }
}
