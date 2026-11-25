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
#define printn(b) cout << ((b) ? "1" : "0") << '\n'
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
    vector<int> enemy;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        enemy = vector<int>(n,-1);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline int get_enemy(int x) {
        return enemy[get(x)];
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        int ex = enemy[x];
        int ey = enemy[y];
        if (x == ey || y == ex) return false;
        if (x != y) {
            p[x] = y;
            if (ey != -1 && ex != -1) p[ex] = ey;
            else if (ey == -1 && ex != -1) {
                enemy[y] = ex;
                enemy[ex] = y;
            }
        }
        return true;
    }
    inline bool fight(int x, int y) {
        x = get(x);
        y = get(y);
        if (enemy[x] != -1) return unite(enemy[x],y);
        else if (enemy[y] != -1) return unite(x,enemy[y]);
        else {
            enemy[x] = y;
            enemy[y] = x;
            return true;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int c,x,y;
    dsu war(n);
    while(cin >> c >> x >> y) {
        if (c == 0) break;
        switch(c) {
            case 1:
                if (!war.unite(x,y)) cout << "-1\n";
                break;
            case 2:
                if (!war.fight(x,y)) cout << "-1\n";
                break;
            case 3:
                printn(war.get(x) == war.get(y));
                break;
            case 4:
                printn(war.get(x) == war.get_enemy(y));
                break;
        }
    }
}
