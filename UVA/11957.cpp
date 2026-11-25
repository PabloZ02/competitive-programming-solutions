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
v<string> board;
int wi;
int wj;
int n;
v<v<ll>> M;
ll solve(int i, int j) {
    if (i == 0) return (j < n && j >= 0 && board[i][j] != 'B');
    else if (j >= n || j < 0 || i < 0 || board[i][j] == 'B') return 0;
    else if (M[i][j] != -1) return M[i][j];
    else {
        ll ans = 0;
        if (j+1 < n) {
            if (board[i-1][j+1] == 'B') ans += (solve(i-2,j+2)) % 1000007;
            else ans += solve(i-1,j+1) % 1000007;
        }
        if (j > 0) {
            if (board[i-1][j-1] == 'B') ans = (ans + solve(i-2,j-2) %1000007) % 1000007;
            else ans = (ans + solve(i-1,j-1) % 1000007) % 1000007;
        }
        M[i][j] = ans;
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    forn (tt,1,TT+1) {
        cin >> n;
        board = v<string>(n);
        M = v<v<ll>>(n, v<ll>(n, -1));
        forn(i,0,n) {
            cin >> board[i];
            forn (j,0,n) {
                if (board[i][j] == 'W') {
                    wi = i;
                    wj = j;
                }
            }
        }
        cout << "Case " << tt << ": " << solve(wi,wj) << "\n";
    }
}
