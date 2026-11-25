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
enum dir{
    N,E,S,W
};

pii move(int dir) {
    if (dir == N) return make_pair(-1,0);
    else if (dir == S) return make_pair(1,0);
    else if (dir == E) return make_pair(0,1);
    else return make_pair(0,-1);
}
bool out_of_bounds(pii pos,int n, int m, v<string> maze) {
    return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m ||
    maze[pos.first][pos.second] == '1';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    bool through = false;
    while(n != 0 || m!= 0) {
        //if (through) cout << "\n";
        //else through = true;
        vi passed(5);
        v<string> maze(n);
        v<vi> passed_maze(n,vi(m));
        forn(i,0,n) {
            cin >> maze[i];
        }
        pii initial_pos = make_pair(n-1,0);
        pii cur_pos = initial_pos;
        int cur_dir = E;
        do {
            int right_dir =  (cur_dir+1)%4;
            pii increase = move(right_dir);
            pii new_pos = make_pair(cur_pos.first+increase.first, cur_pos.second + increase.second);
            if (out_of_bounds(new_pos,n,m,maze)) {
                increase = move(cur_dir);
                new_pos = make_pair(cur_pos.first+increase.first, cur_pos.second + increase.second);
                while(out_of_bounds(new_pos,n,m,maze)) {
                    cur_dir =  cur_dir == 0 ? 3 : cur_dir-1;
                    increase = move(cur_dir);
                    new_pos = make_pair(cur_pos.first+increase.first, cur_pos.second + increase.second);
                } 
            } else cur_dir = right_dir;
            passed_maze[cur_pos.first][cur_pos.second]++;
            cur_pos = new_pos;
        } while(cur_pos != initial_pos);
        forn(i,0,n) {
            forn(j,0,m) {
                if(maze[i][j] == '0' && passed_maze[i][j] < 5) {
                    passed[passed_maze[i][j]]++;
                }
            }
        }
        forn(i,0,5) {
            cout << right << setw(3) << passed[i];
        }
        cout << "\n";
        cin >> n >> m;
    }
}
