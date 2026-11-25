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

    string ms;
    while(getline(cin,ms)) {
        if (ms == "") break;
        int m = stoi(ms);
        vector<string> field(m);
        forn(i,0,m) {
            cin >> field[i];
        }
        int max_min = 0;
        forn(a,0,m) {
            forn(b,0,m) {
                int min_dist = m*m;
                if (field[a][b] == '1') {
                    forn(i,0,m) {
                        forn(j,0,m) {
                            if (field[i][j] == '3') {
                                mineq(min_dist, abs(i-a) + abs(j-b));
                            }
                        }
                    }
                    maxeq(max_min,min_dist);
                }
            }
        }
        cout << max_min << "\n";
        cin.ignore();
    }
}