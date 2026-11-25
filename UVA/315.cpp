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
v<v<bool>> gmat;
vi dfsnum;
vi dfslow;
vi dfsp;
int counter;
pii dfs(int u) {
    int comp = 0;
    int count = 0;
    dfsnum[u] = counter++;
    dfslow[u] = dfsnum[u];
    bool is_articulation = false;
    forn(i,0,g[u].size()) {
        int v = g[u][i];
        if (dfsnum[v] == -1) {
            dfsp[v] = u;
            comp += dfs(v).first;
            is_articulation |= dfslow[v] >= dfsnum[u];
            count++;
            mineq(dfslow[u],dfslow[v]);
        } else if (v != dfsp[u]) mineq(dfslow[u], dfsnum[v]);
    }
    if (u == 0) return {comp,count};
    return {comp + is_articulation,count};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin,line);
    int n = stoi(line);
    while(n != 0) {
        g = vector<vi>(n, vi({}));
        gmat = vector<vector<bool>>(n, vector<bool>(n,false));
        dfsnum = vi(n,-1);
        dfslow = vi(n,-1);
        counter = 0;
        dfsp = vi(n,-1);
        getline(cin,line);
        while(line != "0") {
            string us;
            int ind = 0;
            while(line[ind] != ' ') {
                us.pb(line[ind]);
                ind++;
            } ind++;
            int u = stoi(us);
            u--;
            while(ind < line.size()) {
                string vs;
                while(ind < line.size() && line[ind] != ' ') {
                    vs.pb(line[ind]);
                    ind++;
                } ind++;
                int v = stoi(vs); v--;
                if (!gmat[u][v]) {
                    gmat[u][v] = true;
                    g[u].pb(v);
                }
                if (!gmat[v][u]) {
                    gmat[v][u] = true;
                    g[v].pb(u);
                }
            }

            getline(cin,line);
        }
        pii ans = dfs(0);
        int count = ans.first + (ans.second > 1);
        cout << count << "\n";
        getline(cin,line);
        n = stoi(line);  
    }
}
