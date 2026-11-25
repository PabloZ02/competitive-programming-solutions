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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    v<vi> m(n, vi(n));
    forn(i,0,n) {
        forn(j,0,n) {
            cin >> m[i][j];
            if (i > 0) m[i][j] += m[i-1][j];
            if (j > 0) m[i][j] += m[i][j-1];
            if (i > 0 && j > 0) m[i][j] -= m[i-1][j-1];
        }
    }
    int max_sum = 0;
    forn(i,0,n-1) {
        forn(j,0,n-1) {
            forn(l,i+1,n) {
                forn(k,j+1,n) {
                    int sum = m[l][k];
                    if (i > 0) sum -= m[i-1][k];
                    if (j > 0) sum -= m[l][j-1];
                    if (i > 0 && j > 0) sum += m[i-1][j-1];
                    maxeq(max_sum,sum);
                }
            }
        }
    }
    cout << max_sum << "\n";
}
