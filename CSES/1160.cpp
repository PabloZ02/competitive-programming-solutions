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
int UNPROCESSED = -1;
int LOOPING = 0;
int FINISHED = 1;

vi start;
vi finish;
vi loop_len;
struct nodeInfo {
    bool in_loop;
    int start;
    int loop_rep;
    int loop_dist;
};

nodeInfo dfs(int u, vi& G, vi& status, v<bool>& in_loop, v<pii>& loop_rep_dist) {
    if (status[u] == FINISHED) {
        if (in_loop[u]) return {false,start[u],u,0};
        else return {false,start[u],loop_rep_dist[u].first,loop_rep_dist[u].second};
    }
    else if (status[u] == LOOPING) {
        status[u] = FINISHED;
        in_loop[u] = true;
        loop_rep_dist[u] = {u,0};
        loop_len[u] = 1;
        return {true,start[u],u,0};
    } else {
        status[u] = LOOPING;    
        nodeInfo ni =  dfs(G[u],G,status,in_loop,loop_rep_dist);
        if (status[u] == FINISHED) {
            return {false,start[u],u,0};
        }
        
        status[u] = FINISHED;
        in_loop[u] = ni.in_loop;
        if (ni.in_loop) loop_len[ni.loop_rep]++;
        loop_rep_dist[u] = {ni.loop_rep,ni.loop_dist+1};
        return {ni.in_loop,start[u],ni.loop_rep,ni.loop_dist+1};
    }
}

int dfs_mark(int u, v<vi>& B, int counter) {
    start[u] = counter;
    forn(i,0,B[u].size()) counter = dfs_mark(B[u][i],B,counter+1);
    finish[u] = counter+1;
    return counter+2;
}

void cout_dist(pii rda, pii rdb, int extra) {
    if (rda.first != rdb.first) cout << "-1\n";
    else if (rda.second == 0 && rdb.second == 0) cout << extra << "\n";
    else if (rda.second == 0) cout << loop_len[rda.first]-rdb.second+extra << "\n";
    else if (rdb.second == 0) cout << rda.second+extra << "\n";
    else if(rda.second >= rdb.second) cout << rda.second-rdb.second+extra<< "\n";
    else cout << rda.second+loop_len[rda.first]-rdb.second+extra << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n,q;
    cin >> n >> q;
    v<vi> B(n);
    vi G(n);
    int x;
    forn(i,0,n) {
        cin >> x;
        G[i] = x-1;
        B[x-1].pb(i);
    }
    vi status(n,UNPROCESSED);
    v<bool> in_loop(n,false);
    v<pii> loop_rep_dist(n);
    loop_len = vi(n,-1);
    start = vi(n,-1);
    finish = vi(n,-1);
    forn(i,0,n) {
        if (status[i] == UNPROCESSED) dfs(i,G,status,in_loop,loop_rep_dist);
    }
    int counter = 0;
    forn(i,0,n) {
        if (in_loop[i]) {
            forn(j,0,B[i].size()) {
                int v = B[i][j];
                if (!in_loop[v]) counter = dfs_mark(v,B,counter);
            }
        }
    }
    forn(i,0,q) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        pii rda = loop_rep_dist[a];
        pii rdb = loop_rep_dist[b];
        /*cout << rda.first << " " << rda.second << "\n";
        cout << rdb.first << " " << rdb.second << "\n";
        printb(in_loop[a]);
        printb(in_loop[b]);*/
        if (a == b) cout << "0\n";
        else if (in_loop[a] && !in_loop[b]) cout << "-1\n";
        else if (in_loop[a] && in_loop[b]) cout_dist(rda,rdb,0);
        else if (!in_loop[a] && in_loop[b]) cout_dist(loop_rep_dist[rda.first],rdb,rda.second);
        else {    
            if (rda.first == rdb.first && rda.second > rdb.second && 
                start[a] >= start[b] && finish[a] <= finish[b]) cout << rda.second-rdb.second << "\n";
            else cout << "-1\n";
        }
    }
}