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

    int k;
    cin >> k;
    bool passed = false;
    while(k != 0) {
        if (passed) cout << "\n";
        else passed = true;
        vi v(k);
        forn(i,0,k) cin >> v[i];
        forn(a,0,k-5) {
            forn(b,a+1,k-4) {
                forn(c,b+1,k-3) {
                    forn(d,c+1,k-2) {
                        forn(e,d+1,k-1) {
                            forn(f,e+1,k) {
                                cout << v[a] << " " << v[b] << " " << v[c] 
                                << " " << v[d] << " " << v[e] << " " << v[f] << "\n";
                            }
                        }
                    }
                }
            }
        }

        cin >> k;
    }
}
