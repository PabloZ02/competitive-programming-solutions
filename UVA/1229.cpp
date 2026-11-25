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



v<vi> G;
v<vi> B;
vi comps;
v<bool> marked;

void kos(v<vi>& graph, vi& order, int u, int c) {
    if (comps[u] >= 0) return;
    comps[u] = c;
    forn(i,0,graph[u].size()) kos(graph,order,graph[u][i],c);
    order.pb(u);
}

void dfs(int u, v<string>& ans, v<string>& key2word) {
    if (marked[u]) return;
    marked[u] = true;
    ans.pb(key2word[u]);
    forn(i,0,G[u].size()) {
        dfs(G[u][i],ans,key2word);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while (cin >> n, n != 0) {
        cin.ignore();
        map<string,int> word2key;
        vector<string> key2word;
        int cur = 0;
        G = v<vi>(n, vi());
        B = v<vi>(n,vi());
        string line;
        forn(i,0,n) {
            getline(cin,line);
            stringstream sstr(line);
            string cur_word; sstr >> cur_word;
            if (word2key.count(cur_word) == 0) {
                word2key[cur_word] = cur;
                key2word.pb(cur_word);
                cur++;
            }
            int u = word2key[cur_word];
            while(sstr >> cur_word) {
                if (word2key.count(cur_word) == 0) {
                    word2key[cur_word] = cur;
                    key2word.pb(cur_word);
                    cur++;
                }
                int v = word2key[cur_word];
                G[u].pb(v);
                B[v].pb(u);
            }
        }
        comps = vi(n,-1);
        vi order(n,-1);
        iota(order.begin(),order.end(),0);
        vi dfs_order;
        forr(i,n-1,0) {
            kos(G,dfs_order,order[i],order[i]);
        }
        comps = vi(n,-1);
        forr(i,n-1,0) {
            kos(B,dfs_order,dfs_order[i],dfs_order[i]);
        }
        vector<int> scc_sizes(n,0);
        forn(i,0,n) {
            scc_sizes[comps[i]]++;
        }
        v<string> ans;
        vi starts;
        marked = v<bool>(n,false);
        forn(i,0,n) if (scc_sizes[comps[i]] > 1)  {
            starts.pb(i);
        }
        forn(i,0,starts.size()) dfs(starts[i],ans,key2word);
        sortv(ans);
        cout << ans.size() << "\n";
        cout << ans[0];
        forn(i,1,ans.size()) cout << " " << ans[i];
        cout << "\n";
    }
}
