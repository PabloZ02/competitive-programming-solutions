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

    string nextline; 
    bool passed = false;
    while(getline(cin,nextline)) {
        if(nextline == "") break;
        //if (passed) cout << "\n";
        //else passed = true;
        int m = nextline[0] - '0';
        int n = nextline[2] - '0';
        vector<vector<pii>> g(m);
        forn(i,0,m) {
            int r; cin >> r;
            if (r != 0) {
                vi v;
                forn(j,0,r) {
                    int val; cin >> val;
                    g[i].pb({val-1,0});
                }
                forn(j,0,r) {
                    int val; cin >> val;
                    g[i][j].second = val;
                }
            }
        }
        vector<vector<pii>> gp(n);
        forn(i,0,m) {
            forn(j,0,g[i].size()) {
                gp[g[i][j].first].pb({i,g[i][j].second});
            }
        }
        cout << n << " " << m << "\n";
        forn(i,0,n) {
            cout << gp[i].size();
            if (gp[i].size() == 0) cout << "\n";
            else {
                forn(j,0,gp[i].size()) {
                    cout << " " << gp[i][j].first+1;

                }
                cout << "\n";
                cout << gp[i][0].second;
                forn(j,1,gp[i].size()) {
                    cout << " " << gp[i][j].second;
                }
            }
            cout << "\n";
        }
        cin.ignore();
    }
}
