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

bool vence(char a, char b) {
    return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        int r; int c;
        cin >> r >> c;
        int n; cin >> n;

        vector<string> field;
        forn(i,0,r) {
            string row; cin >> row;
            field.pb(row);
        }
        vector<string> newfield = field; 
        forn(k,0,n) {
            forn(i,0,r) {
                forn(j,0,c) {
                    if (i-1 >= 0 && vence(field[i-1][j], field[i][j])) newfield[i][j] = field[i-1][j];
                    else if (i+1 < r && vence(field[i+1][j], field[i][j])) newfield[i][j] = field[i+1][j];
                    else if (j-1 >= 0 && vence(field[i][j-1], field[i][j])) newfield[i][j] = field[i][j-1];
                    else if (j+1 >= 0 && vence(field[i][j+1], field[i][j])) newfield[i][j] = field[i][j+1];
                }
            }
            field = newfield;
        }
        forn(i,0,r) cout << field[i] << "\n";
        if (TT >= 1) cout << "\n";
    }
}
