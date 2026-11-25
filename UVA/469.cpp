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

vi di = {1,1,1,0,0,-1,-1,-1};
vi dj = {1,0,-1,1,-1,1,0,-1};
vector<string> wetland;
vector<vi> sizes;
void floodwrite(int ans,int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (wetland[i][j] != '.') return;
    wetland[i][j] = 's';
    sizes[i][j] = ans;
    forn(k,0,8) {
        floodwrite(ans,i+di[k],j+dj[k],n,m); 
    }
    
}

int floodfill(int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (wetland[i][j] != 'W') return 0;
    wetland[i][j] = '.';
    int ans = 1;
    forn(k,0,8) {
        ans += floodfill(i+di[k],j+dj[k],n,m); 
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    cin.ignore();
    cin.ignore();
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        string line;
        wetland = {};
        getline(cin,line);
        while(line[0] == 'W' || line[0] == 'L') {
            wetland.pb(line);
            getline(cin,line);
        }
        int n = wetland.size();
        int m = wetland[0].size();
        sizes = vector<vi>(n,vi(m,0));
        forn(i,0,n) {
            forn(j,0,m) {
                sizes[i][j] = 0;
            }
        }
        while(line != "") {
            int ind = 0;
            string as,bs;
            while(line[ind] != ' ') {
                as.pb(line[ind]);
                ind++;
            } ind++;
            while(ind < line.size()) {
                bs.pb(line[ind]);
                ind++;
            }
            int a = stoi(as);
            int b = stoi(bs);
            a--;b--;
            if (sizes[a][b] != 0) cout << sizes[a][b] << "\n";
            else {
                int ans = floodfill(a,b,n,m);
                floodwrite(ans,a,b,n,m);
                cout << ans << "\n";
            }

            getline(cin,line);
        }
    }
}
