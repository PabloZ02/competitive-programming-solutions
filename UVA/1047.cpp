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
vi max_ans;

int solve(vector<pair<int,vector<bool>>>& common, vi& ans, vi& v, int i, int N, int n, int max_cov, int last) {
    if (i == n) {
        int cov = 0;
        forn(j,0,n) {
            cov += v[ans[j]];
        }
        forn(j,0,common.size()) {
            int has = 0;
            forn(k,0,n) {
                has += common[j].second[ans[k]];
            }
            if (has > 1) cov -= (has-1)*common[j].first;
        }
        if (cov > max_cov) {
            max_cov = cov;
            forn(k,0,n) max_ans[k] = ans[k];
        }
        return max_cov;
    }
    else {
        forn(j,last+1,N) {
            ans[i] = j;
            maxeq(max_cov, solve(common,ans,v,i+1,N,n,max_cov,j));
        }
        return max_cov;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N,n;
    cin >> N >> n;
    int casen = 1;
    while(N != 0 || n != 0) {

        cout << "Case Number  " << casen << "\n";
        casen++;
        vi v(N);
        forn(i,0,N) cin >> v[i];
        int max_cov = 0;
        vi ans(n);
        max_ans.resize(n);
        int m; cin >> m;
        vector<pair<int,vector<bool>>> common(m, {0,vector<bool>(N,false)});
        forn(i,0,m) {
            int t; cin >> t;
            forn(j,0,t) {
                int k; cin >> k;
                common[i].second[k-1] = true;
            }
            cin >> common[i].first;
        }
        max_cov = solve(common, ans, v, 0, N, n, max_cov, -1);
        cout << "Number of Customers: " << max_cov << "\n";
        cout << "Locations recommended:";
        forn(i,0,n) cout << " " << max_ans[i]+1;
        cout << "\n";
        cout << "\n";
        cin >> N >> n;
        
    }
}
