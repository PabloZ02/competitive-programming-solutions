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
    forn(casen,1,TT+1) {
        cout << "Case " << casen << ". ";
        int n; cin >> n;
        vi v(n), w(n);
        forn(i, 0, n) cin >> v[i];
        forn(i,0,n) cin >> w[i];
        vector<pair<vi, int>> inc(n);
        vector<pair<vi, int>> dec(n);
        int maxpos = 0;
        int maxneg = 0;
        forn(i,0,n) {
            pii indpos = {i,w[i]};
            pii indneg = {i,w[i]};
            forn(j,0,i) {
                if (inc[j].first[inc[j].first.size()-1] < v[i] && inc[j].second+w[i] > indpos.second) {
                    indpos = {j,inc[j].second+w[i]};
                }
                if (dec[j].first[dec[j].first.size()-1] > v[i] && dec[j].second+w[i] > indneg.second) {
                    indneg = {j,dec[j].second+w[i]};
                }
            }
            inc[i] = inc[indpos.first];
            inc[i].first.pb(v[i]); inc[i].second = indpos.second;
            dec[i] = dec[indneg.first];
            dec[i].first.pb(v[i]); dec[i].second = indneg.second;
            maxeq(maxpos, indpos.second);
            maxeq(maxneg, indneg.second);
        }
        if (maxpos >= maxneg) {
            cout << "Increasing (" << maxpos << "). Decreasing (" << maxneg << ").\n";
        }
        else cout << "Decreasing (" << maxneg << "). Increasing (" << maxpos << ").\n";
    }
}
