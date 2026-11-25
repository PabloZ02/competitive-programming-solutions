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
enum dir {NORTH, EAST,SOUTH,WEST};
v<pii> moved = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,s;
    cin >> n >> m >> s;
    while(n != 0) {
        vector<string> arena(n);
        forn(i,0,n) cin >> arena[i];

        pii r_p;
        dir r_dir;
        forn(i,0,n) {
            forn(j,0,m) {
                char c = arena[i][j];
                if (c != '.' && c != '*' && c != '#') {
                    r_p = {i,j};
                    if (c == 'N') r_dir = NORTH;
                    else if (c == 'L') r_dir = EAST;
                    else if (c == 'S') r_dir = SOUTH;
                    else r_dir = WEST;
                }
            }
        }
        string seq; cin >> seq;
        int stickers = 0;
        forn(i,0,seq.size()) {
            if (seq[i] == 'D') r_dir =(dir) ((r_dir + 1) % 4);
            else if (seq[i] == 'E') r_dir = (dir) (r_dir == NORTH ? WEST : r_dir -1);
            else {
                pii mov = moved[r_dir];
                pii new_pos = {r_p.first + mov.first, r_p.second + mov.second};
                if (new_pos.first >= 0 && new_pos.first < n && new_pos.second >= 0 && new_pos.second < m &&
                arena[new_pos.first][new_pos.second] != '#') {
                    r_p = new_pos;
                    if (arena[r_p.first][r_p.second] == '*') {
                        stickers++;
                        arena[r_p.first][r_p.second] = '.';
                    }
                }
            }
        }
        cout << stickers << "\n";
        cin >> n >> m >> s;
        
    }
}
