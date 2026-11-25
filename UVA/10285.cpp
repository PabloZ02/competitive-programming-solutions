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
v<vi> g;
v<vi> M;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int n,m;
bool outb(int i, int j) {
    return  (i < 0 || i >= n || j < 0 || j>= m);
}

int solve(int i, int j) {
    if (outb(i,j)) return 0;
    else if (M[i][j] != -1) return M[i][j];
    else {
        int ans = 0;
        forn(k,0,4) {
            if (!outb(i+di[k],j+dj[k]) && g[i][j] > g[i+di[k]][j+dj[k]]) 
                maxeq(ans, solve(i+di[k],j+dj[k]));
        }
        ans++;
        M[i][j] = ans;
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        string name;
        cin >> name >> n >> m;
        g = v<vi>(n, vi(m));
        M = v<vi>(n, vi(m,-1));
        forn(i,0,n) {
            forn(j,0,m) {
                cin >> g[i][j];
            }
        }
        int ans = 0;
        forn(i,0,n) {
            forn(j,0,m) {
                maxeq(ans,solve(i,j));
            }
        }
        cout << name << ": " << ans << "\n";
    }
}
