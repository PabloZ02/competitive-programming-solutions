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
int n,m;
vector<string> land;
char continent;
char emptyc;
vi ci = {1,-1,0,0};
vi cj = {0,0,1,-1};
int flood_fill(int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (j < 0) j = m-1;
    if (j == m) j = 0;
    if (land[i][j] != continent) return 0;
    land[i][j] = emptyc;
    int ans = 1;
    forn(k,0,4) {
        ans += flood_fill(i+ci[k],j+cj[k]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        string ns,ms;
        int ind = 0;
        while(line[ind] != ' ') {
            ns.pb(line[ind]);
            ind++;
        } ind++;
        n = stoi(ns);
        while(ind < line.size()) {
            ms.pb(line[ind]);
            ind++;
        }
        m = stoi(ms);
        land = vector<string>(n);
        forn(i,0,n) cin >> land[i];
        int a,b;
        cin >> a >> b;
        continent = land[a][b];
        emptyc = continent == '.' ? 'e' : '.';
        flood_fill(a,b);
        int ans = 0;
        forn(i,0,n) {
            forn(j,0,m) {
                if (land[i][j] == continent) maxeq(ans,flood_fill(i,j));
            }
        }
        cout << ans << "\n";
        cin.ignore(); cin.ignore();
    }
}
