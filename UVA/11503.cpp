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
    vector<int> s;

    dsu(int _n) : n(_n) {
        p.resize(n);
        s.resize(n);
        iota(p.begin(), p.end(), 0);
        forn(i,0,n) s[i] = 1;
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline int unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            s[y] += s[x];
            return s[y];
        }
        return s[x];
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        map<string,int> names;
        int index = 0;
        int f; cin >> f;
        dsu friends(f*2);
        forn(i,0,f) {
            string frst; cin >> frst;
            string snd; cin >> snd;
            int frst_ind; int snd_ind;
            if (names.count(frst) > 0) {
                frst_ind = names[frst];
            } else {
                names[frst] = index;
                frst_ind  = names[frst];
                index++;
            }
            if (names.count(snd) > 0) {
                snd_ind = names[snd];
            } else {
                names[snd] = index;
                snd_ind = names[snd];
                index++;
            }
            cout << friends.unite(frst_ind, snd_ind) << "\n";
        }
    }
}
