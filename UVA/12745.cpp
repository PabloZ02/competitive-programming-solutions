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

using tint = long;

using graph = vector<vector<tint>>;
const tint ACTIVE_FLAG = -1;

void dfs(const graph& G, tint from, tint tag, vector<tint>* components, deque<tint>* order) {
    vector<pair<tint,tint>> stack{{from, from}};
    while(!stack.empty()) {
        pii p = stack.back();
        int v = p.first;
        int f = p.second;
        stack.pop_back();
        if(f == ACTIVE_FLAG) {
            order->push_front(v);
            continue;
        }
        if((*components)[v] != -1) continue;
        (*components)[v] = tag;
        stack.push_back({v, ACTIVE_FLAG});
        forn(i,0,G[v].size())
            stack.push_back({G[v][i],v});
    }
}

// component, order
pair<vector<tint>, deque<tint>> dfs(const graph& G, const deque<tint>& order) {
    deque<tint> res_order;
    vector<tint> components(G.size(), -1);
    tint c = 0;
    for(auto it = order.begin(); it != order.end(); it++)
    {
        tint v = *it;
        if(components[v] == -1)
            dfs(G, v, ++c, &components, &res_order);
    }
    return {components, res_order};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TT; cin >> TT;
    forn(tt,1,TT+1) {
    tint n, m;
    cin >> m >> n;

    auto op = [m](tint v) {return (v+m) % (2*m);};

    graph F(2*m), B(2*m);;
    for(tint i = 0; i < n; ++i) {
        int v,w;
        cin >> v >> w;
        if (v < 0) {
            v++;
            v = op(-v);
        } else v--;
        if (w < 0) {
            w++;
            w = op(-w);
        } else w--;
        B[op(v)].push_back(w);
        B[op(w)].push_back(v);
        F[v].push_back(op(w));
        F[w].push_back(op(v));
        
    }
    deque<tint> order(2*m);
    iota(order.begin(), order.end(), 0);
    vector<tint> cc= dfs(B, dfs(F, order).second).first;

    bool possible = true;
    for(tint v = 0; v < m && possible; ++v) {
        possible = cc[v] != cc[op(v)]; 
    }

    cout << "Case " << tt << ": ";
    possible ? cout << "Yes\n" : cout << "No\n";
    }
}
