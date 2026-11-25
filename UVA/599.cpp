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

int dfs(vector<pair<bool,vi>>&g, vector<bool>& marked, int n) {
    int count = 0;
    if (!marked[n] && g[n].first) {
    marked[n] = true;
    count++;
    forn(i,0,g[n].second.size()) {
        count += dfs(g,marked,g[n].second[i]);
    }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        vector<pair<bool,vi>> g(26);
        string edge; cin >> edge;
        while(edge[0] != '*') {
            g[edge[1] - 'A'].second.pb(edge[3] - 'A');
            g[edge[3] - 'A'].second.pb(edge[1] - 'A');
            cin >> edge;
        }
        string nodes; cin >> nodes;
        fors(i,0,nodes.size(),2) {
            g[nodes[i] - 'A'].first = true;
        }
        vector<bool> marked(26);
        int acorns = 0; int trees = 0;
        forn(i,0,26) {
            int count = dfs(g,marked,i);
            if (count == 1) acorns++;
            else if (count > 1) trees++;
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
}
