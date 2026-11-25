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

ll solve(vector<vector<vector<ll>>> &M, vector<ll> &v, ll d, ll m, ll ans,int ind) {
    if (m == 0) return (ans == 0);
    else if (ind == v.size()) return 0;
    else if (M[ind][m][ans] != -1) return M[ind][m][ans];
    else {
        M[ind][m][ans] = solve(M,v,d,m,ans,ind+1) + solve(M,v,d,m-1,((ans+v[ind]) % d + d) % d,ind+1);
        return M[ind][m][ans];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int setn = 1;
    int n, q;
    cin >> n >> q;
    while(n != 0 || q != 0) {
        cout << "SET " << setn << ":\n"; 
        setn++;
        vector<ll> v(n);
        forn(i,0,n) cin >> v[i];
        forn(qn, 1, q+1) {
            ll d,m;
            cin >> d >> m;
            cout << "QUERY " << qn << ": ";
            vector<vector<vector<ll>>> M(n, vector<vector<ll>>(m+1, vector<ll>(d,-1)));
            cout << solve(M,v,d,m,0,0) << "\n";
        }
        cin >> n >> q;
    }
}
