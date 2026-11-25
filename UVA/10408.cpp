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
int gacd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a == b) return a;
    else if (a > b) return gacd(a-b,b);
    else return gacd(a,b-a);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string l;
    while(getline(cin,l)) {
        int ind = 0;
        string ns,ks;
        while(l[ind] != ' ') {
            ns.pb(l[ind]);
            ind++;
        } ind++;
        while(ind < l.size()) {
            ks.pb(l[ind]);
            ind++;
        }
        int n = stoi(ns);
        int k = stoi(ks);
        vector<pair<double, pii>> ans;
        ans.pb({1.0,{1,1}});
        forn(i,1,n+1) {
            forn(j,i+1,n+1) {
                if (gacd(i,j) == 1) ans.pb({double(i)/double(j),{i,j}});
            }
        }
        sortv(ans);
        cout << ans[k-1].second.first << "/" << ans[k-1].second.second << "\n";
    }
}
