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
int n;
int letters;
vector<string> grid;
v<v<v<v<pair<ll,ll>>>>> M;
int nsq;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
v<v<ll>> paths;
v<v<bool>> marked;
pair<ll,ll> solve(int i, int j, int l) {
    if (l == letters) return {0,1};
    forn(ii,0,n) {
        forn(jj,0,n) {
            paths[ii][jj] = 0;
            marked[ii][jj] = false;
        }
    }
    paths[i][j] = 1;
    marked[i][j] == true;
    int c_l = grid[i][j];
    ll mindist = LLONG_MAX;
    queue<pair<int,pii>> q;
    q.push({0,{i,j}});
    int li,lj;
    while(!q.empty()) {
        pair<int,pii> nq = q.front();
        q.pop();
        int nqi = nq.second.first;
        int nqj = nq.second.second;
        if (marked[nqi][nqj]) continue;
        marked[nq.second.first][nq.second.second] = true;
        if (grid[nqi][nqj] == c_l+1) {
            mindist = nq.first;
            li = nqi;
            lj = nqj;
            
        }
        else if (grid[nqi][nqj] == '#' || (grid[nqi][nqj] > c_l+1 && grid[nqi][nqj] <= 'Z')) continue;
        else {
            forn(k,0,4) {
                int ni = nqi + di[k];
                int nj = nqj + dj[k];
                if (ni >= 0  && ni < n && nj >= 0 && nj < n) {
                    if (!marked[ni][nj]) {
                        paths[ni][nj] += paths[nqi][nqj];
                        paths[ni][nj] %=  20437;
                        q.push({nq.first+1,{ni,nj}});
                    }
                }
            }
        }
    }
    if (mindist == LLONG_MAX) return {mindist,0};
    else {
        ll lpaths = paths[li][lj];
        pair<ll,ll> ans = solve(li,lj,l+1);
        if (ans.first == LLONG_MAX) return ans;
        else return {ans.first+mindist, ((ans.second%20437)* lpaths)%20437};
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int casen = 1;
    while(n != 0) {
        letters = 0;
        nsq = n*n;
        grid = vector<string>(n);
        paths = v<v<ll>>(n, v<ll>(n,0));
        marked = v<v<bool>>(n, v<bool>(n,false));
        int ia,ij;
        forn(i,0,n) {
            cin >> grid[i];
            forn(j,0,n) {
                if (grid[i][j] != '.' && grid[i][j] != '#') {
                    letters++;
                    if (grid[i][j] == 'A') {
                        ia = i;
                        ij = j;
                    }
                }
            }
        }
        //M = v<v<v<v<pair<ll,ll>>>>>(n, v<v<v<pair<ll,ll>>>>
        //(n, v<v<pair<ll,ll>>>(letters+1, v<pair<ll,ll>>(n*n, {-1,-1}))));
        pair<ll,ll> ans = solve(ia,ij,1);
        cout << "Case " << casen << ": ";
        casen++;
        if(ans.first == LLONG_MAX) cout <<"Impossible\n";
        else cout << ans.first << " " << ans.second << "\n";
        cin >> n;
    }
}
