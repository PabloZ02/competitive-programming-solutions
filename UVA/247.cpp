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
v<vi> g;
vi dfs_num;
vi dfs_low;
v<bool> visited;
vector<string> ind_names;
vi ans;
int counter_dfs;

void dfs(int u) {
    dfs_low[u] = dfs_num[u] = counter_dfs++;
    ans.pb(u);
    visited[u] = true;
    forn(i,0,g[u].size()) {
        int v = g[u][i];
        if (dfs_num[v] == -1) dfs(v);
        if (visited[v]) mineq(dfs_low[u],dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        int v = ans[ans.size()-1];
        cout << ind_names[v];
        ans.pop_back();
        visited[v] = false;
        while(v != u) {
            v = ans[ans.size()-1];
            ans.pop_back();
            cout << ", " << ind_names[v];
            visited[v] = false;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int dataset = 1;
    bool passed = false;
    while(n != 0 || m != 0) {
        if (passed) cout << "\n";
        else passed = true;
        cout << "Calling circles for data set " << dataset << ":\n";
        dataset++;
        v<v<bool>> gmat(n,v<bool>(n,false));
        g = v<vi>(n, vi({}));
        dfs_num = vi(n,-1);
        dfs_low = vi(n,-1);
        visited = v<bool>(n,false);
        counter_dfs = 0;
        ind_names = {};
        ans = {};
        map<string, int> names;
        int new_ind = 0;
        forn(i,0,m) {
            string n1,n2;
            cin >> n1 >> n2;
            int ni1, ni2;
            if (names.count(n1) > 0) ni1 = names[n1];
            else {
                ni1 = new_ind;
                names[n1] = ni1;
                new_ind++;
                ind_names.pb(n1);
            }
            if (names.count(n2) > 0) ni2 = names[n2];
            else {
                ni2 = new_ind;
                names[n2] = ni2;
                new_ind++;
                ind_names.pb(n2);
            }
            if (!gmat[ni1][ni2]) {
                gmat[ni1][ni2] = true;
                g[ni1].pb(ni2);
            }
        }
        forn(i,0,n) {
            if (ind_names.size() > i && dfs_num[i] == -1) dfs(i);
        }
        cin >> n >> m;
    }
}
