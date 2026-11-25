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

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int nv;
    while(cin >> nv) {
        int nh; cin >> nh;
        vector<vector<vector<bool>>>rest(nv, vector<vector<bool>>(nh,{1,1,1,1}));
        int r; cin >> r;
        int x1,y1,x2,y2;
        forn(i,0,r) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (y2 > y1) rest[x1][y1][0] = false;
            else if (y2 < y1) rest[x1][y1][1] = false;
            else if (x2 > x1) rest[x1][y1][2] = false;
            else if (x2 < x1) rest[x1][y1][3] = false;
        }
        vector<pii> monit(501,{-1,-1});
        int m; cin >> m;
        int t,x,y;
        forn(i,0,m) {
            cin >> t >> x >> y;
            monit[t] = {x,y};
        }
        if (nv == nh && nv == 1) {
            cout << "0\n";
            continue;
        }
        vector<vector<int>> passed(nv, v<int>(nh, -1));
        passed[0][0] = 0;
        queue<pair<pii,int>> q;
        q.push({{0,0},0});
        bool found = false;
        while(!found) {
            pair<pii,int> p = q.front();
            q.pop();
            int xp = p.first.first;
            int yp = p.first.second;
            int d = p.second;
            d++;
            forn(k,0,4) {
                int xn = xp+di[k];
                int yn = yp+dj[k];
                pii newp = {xn,yn};
                if (xn < 0 || yn < 0 || xn >= nv || yn >= nh || passed[xn][yn] != -1 || 
                    !rest[xp][yp][k]) continue;
                else if (d <= 500 && monit[d] == newp) {
                    if (passed[xp][yp] != d) {
                        passed[xp][yp] = d;
                        q.push({{xp,yp},d});
                    }
                } else {
                    if (xn == nv-1 && yn == nh-1) {
                    found = true;
                    cout << d << "\n";
                    break;
                    }
                    passed[xn][yn] = d;
                    q.push({{xn,yn},d});
                }
            }
        }
    }
}
