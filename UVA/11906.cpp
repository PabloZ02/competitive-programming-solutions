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
int r,c,m,n,w;
vector<vector<bool>> water;
vector<vector<int>> marked;
vi options;
int ODD = 1;
int EVEN = 2;
int EMPTY = 0;
int PENDING = 3;
int distinct = 8;
bool valid(int i, int j) {
    return (i >= 0 && i < r && j >= 0 && j < c  && !water[i][j]);
}
void solve(int i, int j) {
    marked[i][j] = PENDING;
    int am = 0;
    forn(k,0,distinct) {
        int i2 = i+options[k];
        int j2 = j+options[(k+4)%8];
        if (valid(i2,j2)) {
            am++;
            if (!marked[i2][j2]) solve(i2,j2);
        }
    }
    //if (am == 0);
    if (am % 2== 0) {
        marked[i][j] = EVEN;
    } else marked[i][j] = ODD;
    return;
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    forn(t,1,TT+1) {
        
        cin >> r >> c >> m >> n >> w;
        water = vector<vector<bool>>(r, vector<bool>(c,false));
        marked = vector<vector<int>>(r, vector<int>(c,EMPTY));
        forn(i,0,w) {
            int a,b;
            cin >> a >> b;
            water[a][b] = true;
        }
        options = {n,-n,n,-n,m,m,-m,-m};
        distinct = 8;
        if (n == m) {
            distinct = 4;
            options = {n,n,-n,-n,n,-n,n,-n};
        }
        else if (n == 0 || m == 0) {
            int k;
            if (n == 0) k = m;
            else k = n;
            distinct = 4;
            options = {k,-k,0,0,0,0,k,-k};
        }
        solve(0,0);
        int even = 0;
        int odd = 0;
        forn(i,0,r) {
            forn(j,0,c) {
                if (marked[i][j] == EVEN) even++;
                else if (marked[i][j] == ODD) odd++;
            }
        }
        cout << "Case " << t << ": " << even << " " << odd << "\n";
    }
}
