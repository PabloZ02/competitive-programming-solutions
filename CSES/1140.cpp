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
//template <typename T>
//using v = vector<T>;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vector<vector<T>>>;
// clang-format on
//--------------------------------------
vector<pair<pii,ll>> v;
vector<ll> M;
int n;
bool cmp(int i, pair<pii,ll> p) {return p.first.first > i;}

ll solve(int i) {
    if (i == n) return 0;
    else if (M[i] == -1) {

        int b = v[i].first.second;
        auto it = upper_bound(its(v),b,cmp);
        M[i] = max(solve(i+1),v[i].second+solve(it-v.begin()));
    }
    return M[i];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    v = vector<pair<pii,ll>>(n);
    M = vector<ll>(n,-1);
    int a,b;
    ll c;
    forn(i,0,n) {
        cin >> a >> b >> c;
        v[i] = {{a,b},c};
    } 
    sortv(v);
    cout << solve(0) << "\n";

}
