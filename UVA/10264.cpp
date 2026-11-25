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

    int n;
    while(cin >> n) {
        int npow = 2 << (n-1);
        vi weights(npow);
        forn(i,0,npow) cin >> weights[i];
        int max_weight = 0;
        forn(i,0,npow) {
            int weight = 0;
            int max_nweight = 0;
            forn(j,0,n) {
                int neighbor = i ^ (1 << j);
                weight += weights[neighbor];
                int neighbor_weight = 0;
                forn(k,0,n) {
                    neighbor_weight += weights[neighbor ^ (1 << k)];
                }
                maxeq(max_nweight,neighbor_weight);
            }
            maxeq(max_weight,weight+max_nweight);
        }
        cout << max_weight << "\n";
    }
}
