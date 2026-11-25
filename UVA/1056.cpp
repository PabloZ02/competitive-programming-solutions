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

    int n,m;
    cin >> n >> m;
    int casen = 1;
    while(n !=0 ) {
        map<string,int> str2int;
        int ind = 0;
        v<v<ll>> mat(n, v<ll>(n,INT32_MAX));
        forn(i,0,n) mat[i][i] = 0;
        v<string> st(2);
        forn(i,0,m) {
            cin >> st[0] >> st[1];
            forn(j,0,2) {
                if (str2int.count(st[j]) == 0) {
                    str2int[st[j]] = ind;
                    ind++;
                }
            }
            int s1 = str2int[st[0]];
            int s2 = str2int[st[1]];
            mat[s1][s2] = 1;
            mat[s2][s1] = 1;
            } 
        forn(k,0,n) {
            forn(i,0,n) {
                forn(j,0,n) {
                    mineq(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        bool disc = false;
        int ans = 0;
        forb(i,0,n,!disc) {
            forb(j,i+1,n,!disc) {
                disc = mat[i][j] == INT32_MAX;
                maxeq(ans,int(mat[i][j]));
            }
        }
        cout << "Network " << casen << ": ";
        casen++;
        if (disc) cout << "DISCONNECTED\n";
        else cout << ans << "\n";
        cout << "\n";


        cin >> n >> m;
    }
}
