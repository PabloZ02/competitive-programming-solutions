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
vi sol;
void solve(int v, int n, vector<vector<bool>>& g, vi& cur_sol) {
    if (v <= n) {
        if (cur_sol.size() > sol.size()) sol = cur_sol;
    } if (v < n) {
        forn(i,v,n) {
            bool compatible = true;
            forb(j,0,cur_sol.size(),compatible) compatible = !g[i][cur_sol[j]];
            if (compatible) {
                cur_sol.pb(i);
                solve(i+1,n,g,cur_sol);
                cur_sol.pop_back();
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        int n, k;
        cin >> n >> k;
        sol = {};
        v<v<bool>> g(n, v<bool>(n,false));
        forn(i,0,k) {
            int a,b;
            cin >> a >> b;
            g[a-1][b-1] = true;
            g[b-1][a-1] = true;
        }
        vi cur_sol = {};
        solve(0,n,g,cur_sol);
        cout << sol.size() << "\n";
        cout << sol[0]+1;
        forn(i,1,sol.size()) cout << " " << sol[i]+1;
        cout << "\n";
    }
}
