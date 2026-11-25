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
int n,b1,b2;
v<pii> islands;
v<v<v<double>>> M;

double dist(int i, int j) {
    return hypot(islands[j].first - islands[i].first, islands[j].second-islands[i].second);
}

double solve(int i, int j, bool b1i) {
    if (i == n-1 || j == n-1) return dist(j,i);
    else if (M[i][j][b1i] < 0.5) {
        int nind = max(i,j)+1;
        if (nind == b1) {
            if (!b1i) M[i][j][b1i] = solve(i,nind,b1i) + dist(j,nind);
            else M[i][j][b1i] = solve(nind,j,b1i) + dist(i,nind);
        } else if (nind == b2) {
            if (b1i) M[i][j][b1i] = solve(i,nind,b1i) + dist(j,nind);
            else M[i][j][b1i] = solve(nind,j,b1i) + dist(i,nind);
        } else {
            M[i][j][b1i] = min(solve(i,nind,b1i) + dist(j,nind),solve(nind,j,b1i) + dist(i,nind));
            if (nind > b2) M[i][j][!b1i] = M[i][j][b1i];
        }
    }
    return M[i][j][b1i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    while(cin >> n >> b1 >> b2, n != 0) {
        islands = v<pii>(n);
        M = v<v<v<double>>>(n, v<v<double>>(n,v<double>(2,-1)));
        int a,b;
        if (b1 > b2) swap(b1,b2);
        forn(i,0,n) {
            cin >> a >> b;
            islands[i] = {a,b};
        }
        double ans = max(solve(0,0,true),solve(0,0,false));
        cout << "Case " << tt++ << ": " <<  fixed << setprecision(2) << ans << "\n";
        bool b1i = ans == M[0][0][true];
        vi ians = {0};
        vi jans = {0};
        int lasti = 0;
        int lastj = 0;
        forn(ind,1,n-1) {
            if (M[lasti][lastj][b1i] == M[ind][lastj][b1i] + dist(lasti,ind)) {
                ians.pb(ind);
                lasti = ind;
            } else {
                jans.pb(ind);
                lastj = ind;
            }
        }
        ians.pb(n-1);
        if (ians.size() == 1 || ians[1] != 1) swap(ians,jans);
        cout << ians[0];
        forn(i,1,ians.size()) cout << " " << ians[i];
        forr(j,jans.size()-1,0) cout << " " << jans[j];
        cout << "\n";
    }
}
