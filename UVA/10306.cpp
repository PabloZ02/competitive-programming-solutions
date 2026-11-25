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
vector<pii> ecoins(40);
int m,s;
int solve(vector<vi> &M, int x, int y) {
    if (fabs(sqrt(x*x+y*y)-s) < 1e-6) return 0;
    else if (sqrt(x*x+y*y) > s) return inf;
    else if (M[x][y] != -1) return M[x][y];
    int ans = inf;
    forn(i,0,m) {
        int posans = solve(M,x+ecoins[i].first,y+ecoins[i].second);
        if (ans > posans) {
            ans = posans+1;
        }
    }
    return M[x][y] = ans;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    forn(ignore,0,n) {
        cin >> m >> s;
        vector<vi> M(s,vi(s,-1));
        forn(i, 0, m) {
            int conval, intecval;
            cin >> conval >> intecval;
            ecoins[i] = {conval, intecval};
        }
        int sol = solve(M,0,0);
        if (sol == inf) cout << "not possible\n";
        else cout << sol << "\n";
    }
}
