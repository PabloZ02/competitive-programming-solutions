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
    bool looped = false;
    while(n != 0) {
        if (looped) cout << "\n";
        else looped = true;
        vi v(n);
        forn(i,0,n) cin >> v[i];
        sortv(v);
        int maxrep = 1;
        int curmax = 1;
        int num = v[0];
        forn(i,1,n) {
            if (v[i] == num) curmax++;
            else {
                maxeq(maxrep,curmax);
                curmax = 1;
                num = v[i];
            }
        }
        maxeq(maxrep,curmax);
        vector<vi> bags(maxrep);
        int j = 0;
        forn(i,0,n) {
            bags[j].pb(v[i]);
            j = (j+1) % maxrep;
        }
        cout << bags.size() << "\n";
        forn(i,0,bags.size()) {
            cout << bags[i][0];
            forn(j,1,bags[i].size()) {
                cout << " " << bags[i][j];
            }
            cout << "\n";
        }
        cin >> n;
    }
}
