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

    int m; int n;
    cin >> m >> n;
    while(m != 0 || n != 0) {
        int res;
        if (m == 1 || n == 1) res = m*n;
        else if (m == 2 || n == 2) {
            int extra = m == 2 ? n : m;
            if (extra % 4 == 2) res = (n * m + 4) / 2;
            else if (extra % 4 != 0) res = (n*m+2)/2;
            else res = (n*m)/2;
        }
        else if (n % 2 == 1 && m % 2 == 1) res = (n*m + 1)/2;
        else res = (n*m)/2;        
        cout << res << " knights may be placed on a " << m << " row " << n << " column board.\n"; 
        cin >> m >> n;
    }
}
