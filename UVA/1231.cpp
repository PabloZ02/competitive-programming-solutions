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
int t,h,f;
v<vi> trees(2001, vi(2001,0));
v<vi> M(2001,vi(2001,-1));
vi Mh(2001,-1);
int solve(int height) {
    //cout << treenum << " " << height << endl;
    if (height < 0) return 0;
    else if (Mh[height] == -1) {
        int ans = 0;
        if (height > f) {
            if (Mh[height-f] == -1) solve(height-f);
            if (M[0][height-1] == -1) solve(height-1);
            forn(i,0,t) {
                int ti_ans = 0;
                if (Mh[height-f] == -1) solve(height-f);
                maxeq(ti_ans, Mh[height-f]);
                maxeq(ti_ans,M[i][height-1]);
                ti_ans += trees[i][height];
                M[i][height] = ti_ans;
                maxeq(ans,ti_ans);
            }
            Mh[height] = ans;
        }
        else if (height >= 1) {
            if (M[0][height-1] == -1) solve(height-1);
            forn(i,0,t) {
                int ti_ans = 0;
                maxeq(ti_ans,M[i][height-1]);
                ti_ans += trees[i][height];
                M[i][height] = ti_ans;
                maxeq(ans,ti_ans);
            }
            Mh[height] = ans;
        }
    }   
    return Mh[height];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> t >> h >> f;
        forn(i,0,t) {
            forn(j,0,h+1) {
                trees[i][j] = 0;
            }
        }
        forn(i,0,t) {
            forn(j,0,h+1) {
                M[i][j] = -1;
            }
        }
        forn(i,0,h+1) Mh[i] = -1;
        int a,ac;
        forn(i,0,t) {
            cin >> a;
            forn(j,0,a) {
                cin >> ac;
                trees[i][ac]++;
            }
        }
        forn(i,0,t) maxeq(Mh[0], trees[i][0]);
        cout << solve(h) << "\n";
    }
    cin >> TT;
}
