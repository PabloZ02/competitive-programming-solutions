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

    int tt = 1;
    int n,m;
    cin >> n >> m;
    bool passed = false;
    while(n != 0) {
        if (passed) cout << "\n";
        else passed = true;
        v<string> minefield(n);
        v<string> ans_minefield(n);
        forn(i,0,n) {
            cin >> minefield[i]; 
            ans_minefield[i] = minefield[i];
        }
        forn(i,0,n) {
            forn(j,0,m) {
                if(minefield[i][j] != '*') {
                    int count = 0;
                    if (i > 0 && j > 0) count += minefield[i-1][j-1] == '*';
                    if (i > 0) count += minefield[i-1][j] == '*';
                    if(j > 0) count += minefield[i][j-1] == '*';
                    if(i > 0 && j < m-1) count += minefield[i-1][j+1] == '*';
                    if (i < n-1) count += minefield[i+1][j] == '*';
                    if (j < m-1) count += minefield[i][j+1] == '*';
                    if (i < n-1 && j > 0) count += minefield[i+1][j-1] == '*';
                    if (i < n-1 && j < m-1) count += minefield[i+1][j+1] == '*';
                    ans_minefield[i][j] = count + '0';
                } 
            }
        }
        cout << "Field #" << tt << ":\n";
        tt++;
        forn(i,0,n) cout << ans_minefield[i] << "\n";


        cin >> n >> m;
    }
}
