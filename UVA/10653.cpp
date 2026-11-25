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
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
int R,C;
v<v<bool>> bombs;
bool out(pii p) {
    return p.first < 0 || p.first >= R || p.second < 0 || p.second >= C || bombs[p.first][p.second];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    cin >> R >> C;
    while(R != 0) {
        bombs = v<v<bool>> (R, v<bool>(C,false));
        int rows; cin >> rows;
        forn(ig,0,rows) {
            int r; cin >> r;
            int n; cin >> n;
            forn(i,0,n) {
                int c; cin >> c;
                bombs[r][c] = true;
            }
        }
        pii s;
        cin >> s.first >> s.second;
        pii t;
        cin >> t.first >> t.second;
        v<vi> dist(R, vi(C, INT32_MAX));
        dist[s.first][s.second] = 0;
        queue<pii> q;
        q.push(s);
        pii next = s;
        while(!q.empty() && next != t) {
            next = q.front();
            q.pop();
            int d = dist[next.first][next.second];
            forn(i,0,4) {
                pii v = {next.first+di[i],next.second+dj[i]};
                if (!out(v) && dist[v.first][v.second] == INT32_MAX) {
                    dist[v.first][v.second] = d+1;
                    q.push(v);
                }
            }
        }
        cout << dist[t.first][t.second] << "\n";

        cin >> R >> C;
    }
}
