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
        cout << "Case #" << casen << ": ";
        int n; cin >> n;
        int m; cin >> m;
        ll k; cin >> k;
        vector<vector<ll>> M(n, vector<ll>(m));
        forn(i,0,n) {
            forn(j,0,m) {
                cin >> M[i][j];
                if (i > 0) M[i][j] += M[i-1][j];
                if (j > 0) M[i][j] += M[i][j-1];
                if (i > 0 && j > 0) M[i][j] -= M[i-1][j-1];
            }
        }
        ll maxsum = 0;
        ll maxarea = 0;
        forn(i,0,n) {
            forn(j,0,m) {
                ll sum = M[i][j];
                if (i > 0) sum -= M[i-1][j];
                if (j > 0) sum -= M[i][j-1];
                if (i > 0 && j > 0) sum+= M[i-1][j-1];
                if (sum <= k) {
                forn(a,i,n) {
                    sum = M[a][j];
                    if (i > 0) sum -= M[i-1][j];
                    if (j > 0) sum -= M[a][j-1];
                    if (i > 0 && j > 0) sum+= M[i-1][j-1];
                    if (sum > k) break;
                    forn(b,j,m) {
                        sum = M[a][b];
                        if (i > 0) sum -= M[i-1][b];
                        if (j > 0) sum -= M[a][j-1];
                        if (i > 0 && j > 0) sum += M[i-1][j-1];
                        if (sum > k) break;
                        ll area = (b-j+1)*(a-i+1);                  
                        if (area > maxarea || (area == maxarea && sum < maxsum)) {
                            maxsum = sum;
                            maxarea = area;
                        }
                    }
                }
                }     
            }
        }
        cout << maxarea << " " << maxsum << "\n";
    }
}
