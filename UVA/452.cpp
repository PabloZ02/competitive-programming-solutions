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

vi topov;
v<bool> vis;
v<pair<int, vi>> g;
void dfs(int u) {
    vis[u] = true;
    forn(i,0,g[u].second.size()) {
        int v = g[u].second[i];
        if (!vis[v]) dfs(v);
    }
    topov.pb(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    cin.ignore();
    cin.ignore();
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        string line;
        vi str2ind(26,-1);
        int ind = 0;
        g = {};
        getline(cin,line);
        vi sv;
        while(line != "") {
            if (str2ind[line[0]-'A'] == -1) {
                str2ind[line[0]-'A'] = ind;
                ind++;
                g.pb({0,{}});
            }
            int cur = str2ind[line[0]-'A'];
            int lind = 2;
            string days;
            while(lind < line.size() && line[lind] != ' ') {
                days.pb(line[lind]);
                lind++;
            } lind++;
            g[cur].first = -1*stoi(days);
            bool haspred = false;
            while(lind < line.size()) {
                if(haspred == false) haspred = true;
                if (str2ind[line[lind]-'A'] == -1) {
                str2ind[line[lind]-'A'] = ind;
                ind++;
                g.pb({0,{}});
            }
            int prev = str2ind[line[lind]-'A'];
            g[prev].second.pb(cur);
            lind++;
            }
            if (!haspred) sv.pb(cur);
            getline(cin,line);
        }
        int n = ind;
        topov = {};
        vis = v<bool>(n,false);
        vi dist(n,INT32_MAX);
        forn(i,0,sv.size()) {
            dist[sv[i]] = g[sv[i]].first;
            dfs(sv[i]);
        }
        forr(i,n-1,0) {
            int u = topov[i];
            forn(j,0,g[u].second.size()) {
                int v = g[u].second[j];
                mineq(dist[v],dist[u]+g[v].first);
            }
        }
        int ans = 0;
        forn(i,0,n) mineq(ans,dist[i]);
        cout << -ans << "\n";
        
        
    }
}
