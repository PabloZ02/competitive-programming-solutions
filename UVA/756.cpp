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

    int p,e,i,d;
    int tt = 1;
    while(1) {
        cin >> p >> e >> i >> d;
        if (p == -1) break;
        vi vars(5);
        vi mods = {23,4,7,3,11};
        vi rems = {p,e,e,i,i};
        
        forn(k,0,5) {
            if (rems[k] == 0) continue;
            rems[k] %= mods[k];
            int ymult = 1;
            forn(k2,0,5) {
                if (k != k2) ymult *= mods[k2];
            }
            int y = 0;
            while(((ymult*y) % mods[k]) != rems[k]) y++;
            vars[k] = ymult*y;
        }
        int modf = 23*4*7*3*11;
        int ans = 0;
        forn(k,0,5) ans += vars[k];
        ans %= modf;
        if (ans == 0) ans = modf;
        cout << "Case " << tt << ": the next triple peak occurs in ";
        if (d < ans) cout << ans-d;
        else cout << modf+ans-d;
        cout << " days.\n";
        tt++;
    }
}
