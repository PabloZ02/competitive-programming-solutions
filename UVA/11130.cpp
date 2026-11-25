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

    double a,b,v,A,s;
    cin >> a >> b >> v >> A >> s;
    while(a != 0) {
        A = A*(M_PI / 180);
        double hv = cos(A)*v;
        double vv = sin(A)*v;
        int hans = 0;int vans = 0;
        double hfin = (hv*s)/2;
        if (hfin > (a/2)) {
            hans = 1 + (hfin-a/2)/a;
        }
        double vfin = (vv*s)/2;
        if (vfin > (b/2)) {
            vans = 1 + (vfin-b/2)/b;
        }
        cout << hans << " " << vans << "\n";
        cin >> a >> b >> v >> A >> s;
    }
}
