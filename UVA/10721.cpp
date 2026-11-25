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
int m;
ll solve(int i, int k, vector<vector<ll>>&M) {
    if (i == 0 && k == 0) return 1;
    else if (i <= 0 || k <= 0)return 0;
    else if (M[i][k] != -1) return M[i][k];
    else {
        ll ans = 0;
        forn(suc,1,m+1) {
            ans += solve(i-suc,k-1,M);
        }
        M[i][k] = ans;
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        string ns,ks,ms;
        int ind = 0;
        while(line[ind] != ' ') {
            ns.pb(line[ind]);
            ind++;
        }ind++;
        int n = stoi(ns);
        while(line[ind] != ' '){
            ks.pb(line[ind]);
            ind++;
        } ind++;
        int k = stoi(ks);
        while(ind < line.size()) {
            ms.pb(line[ind]);
            ind++;
        }
        m = stoi(ms);
        vector<vector<ll>> M(n+1, vector<ll>(k+1,-1));
        cout << solve(n,k,M) << "\n";
    }
}
