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
int m,n;
v<vi> M;
v<pii> vpf;
int favormin = -500;
int solve(int i, int c) {
    if (i == n && c == 0) return 0;
    else if (c < 0 || (i == n && c > 0)) return favormin;
    
    else if (M[i][c] == -1) {
        M[i][c] = max(solve(i+1,c-vpf[i].first)+vpf[i].second, solve(i+1,c));
    }
    return M[i][c];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        stringstream sstr(line);
        sstr >> m >> n;
        vpf = v<pii>(n);
        M = v<vi>(n+1, vi(m+201,-1));
        int p,f;
        forn(i,0,n) {
            cin >> p >> f;
            vpf[i] = {p,f};
        }
        int ans = 0;
        forn(i,1,m+1) maxeq(ans,solve(0,i));
        int dist2k = 2001-m;
        if (dist2k <= 200) {
            forn(i,m+max(dist2k,0),max(2001,m+1)+min(200,200-dist2k+1)) {
                maxeq(ans,solve(0,i));
            }
        }
        cout << ans << "\n";
        if (n != 0)cin.ignore();
    }
}
