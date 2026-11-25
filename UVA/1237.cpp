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

    int TT;
    cin >> TT;
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        int d; cin >> d;
        vector<tuple<string,int,int>> cars(d);
        forn(i,0,d) {
            string carname; int l, h;
            cin >> carname >> l >> h;
            cars[i] = {carname,l,h};
        }
        int q; cin >> q;
        forn(i,0,q) {
            int p; cin >> p;
            int ind = -1;
            forn(j,0,d) {
                if (p >= get<1>(cars[j]) && p <= get<2>(cars[j])) {
                    if (ind != -1) {
                        ind = -1;
                        break;
                    } else ind = j;
                }
            }
            if (ind != -1) cout << get<0>(cars[ind]) << "\n";
            else cout << "UNDETERMINED\n";
        }
    }
}
