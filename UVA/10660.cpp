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
    while (TT--) {
        int n; cin >> n;
        v<vi> city(5, vi(5,0));
        forn(k,0,n) {
            int i,j,p;
            cin >> i >> j >> p;
            city[i][j] = p;
        }
        vi ans = {0,1,2,3,4};
        int minDist = INT32_MAX;
        forn(a,0,21) {
            forn(b,a+1,22) {
                forn(c,b+1,23) {
                    forn(d,c+1,24) {
                        forn(e,d+1,25) {
                            int dist = 0;
                            forn(i,0,5) {
                                forn(j,0,5) {
                                    if (city[i][j] != 0) {
                                        int da = abs(i-a/5) + abs(j-a%5);
                                        int db = abs(i-b/5) + abs(j-b%5);
                                        int dc = abs(i-c/5) + abs(j-c%5);
                                        int dd = abs(i-d/5) + abs(j-d%5);
                                        int de = abs(i-e/5) + abs(j-e%5);
                                        dist += city[i][j]*min({da,db,dc,dd,de});
                                    }
                                }
                            }
                            if (dist < minDist) {
                                minDist = dist;
                                ans = {a,b,c,d,e};
                            }
                        }
                    }
                }
            }
        }
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << "\n";
    }
}
