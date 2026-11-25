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
        int a,b,c;
        cin >> a >> b >> c;
        int minb,minc,mina;
        minb = (int) cbrt(b);
        minc = (int) sqrt(c)+1;
        int minint = min(minb,minc);
        vi ans(3);
        bool found = false;
        forb(i,-minint,minint+1,!found) {
            forb(j,-minc,minc+1,!found) {
                int k = a-i-j;
                if (k != i && k != j && i != j && i*j*k == b && i*i+j*j+k*k == c) {
                    ans = {k,j,i};
                    sortv(ans);
                    found = true;
                }
            }
        }
        if (found) cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";       
        else cout << "No solution.\n"; 
    }
}
