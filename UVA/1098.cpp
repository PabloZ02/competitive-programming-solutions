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
using used = bitset<88>;
using umap = unordered_map<used,int>;
v<pii> rc(4);
vi quarters(4);
vi di = {0,0,1,-1};
vi dj = {1,-1,0,0};

int n,m;
int steps;

bool cant_visit(int r, int c, used& cur_used) {
    return (r < 0 || r >= n || c < 0 || c >= m || cur_used.test(r*10+c));
}

bool not_solvable(int r, int c, used& cur_used) {
    bool up = cant_visit(r+1,c,cur_used);
    bool down = cant_visit(r-1,c,cur_used);
    bool left = cant_visit(r,c-1,cur_used);
    bool right = cant_visit(r,c+1,cur_used);
    return (!up && !down && left && right) || (up && down && !left && !right);
}

int solve(int r, int c,int i,  used cur_used) {
    
    if (i == steps && r == 0 && c == 1) return 1;
    bool respects_quarter = true;
    forn(k,0,4) {   
        respects_quarter &= (i != quarters[k] || 
        (i == quarters[k] && r == rc[k].first && c == rc[k].second));
        respects_quarter &= ((r != rc[k].first || c != rc[k].second) || 
        (i == quarters[k] && r == rc[k].first && c == rc[k].second));
        //if (r == 2 && c == 1 && respects_quarter) cout << "yay" << endl;
        //if (r == 2 && c == 1 && !respects_quarter) cout << "nay" << endl;
    }
    //cout << r << " " << c << " " << i << endl;
    if (!respects_quarter) return 0;
    
    if (cant_visit(r,c,cur_used) || not_solvable(r,c,cur_used)) return 0;
    int next_ind = 0;
    while(i > quarters[next_ind]) next_ind++;
    if (abs(r-rc[next_ind].first) + abs(c-rc[next_ind].second) > quarters[next_ind]-i) return 0;
    int ans = 0;
    forn(k,0,4) {
        ans += solve(r+di[k],c+dj[k],i+1,cur_used | used().set(r*10+c));
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT = 1;
    rc[3] = {0,1};
    while(1) {
        cin >> n >> m;
        if (n == 0) break;
        
        forn(i,0,3) {
            int a,b;
            cin >> a >> b;
            rc[i] = {a,b};
        }
        steps = n*m;
        quarters[3] = steps;
        forn(i,0,3) quarters[i] = ((i+1)*n*m)/4;
        cout << "Case " << TT++ << ": " << solve(0,0,1,used()) << "\n";
        



    }
}
