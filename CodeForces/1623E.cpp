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
struct Node {
    int p;
    int l;
    int r;
    int h;
    bool dup;
};
v<Node> nodes;
string tree;
vi order;
vi reverse_order;
v<bool> lesser;
int n;
int ind;


void inorder(int u) {
    if (u < 0) return;
    if (u != 0) nodes[u].h = nodes[nodes[u].p].h+1;
    inorder(nodes[u].l);
    order[ind] = u;
    reverse_order[u] = ind;
    ind++;
    inorder(nodes[u].r);
}

int form_ans(int u,int k) {
    if (u == -1) return 0;
    if (k < nodes[u].h) return 0;
    //if ((p == -1 || (nodes[p].r == u && tree[order[p]] <= tree[order[u]])) && (lesser[order[u]]))  
    int p1 = form_ans(nodes[u].l,k);
    if (lesser[reverse_order[u]] || p1) {
        nodes[u].dup = true;
        int p2 = form_ans(nodes[u].r,k-p1);
        //cout << u << "a\n";
        return 1 + p1 + p2;
        
    }
    //cout << u << "c\n";
    return 0;
    
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k;
    cin >> n >> k;
    cin >> tree;
    nodes = v<Node>(n);
    int le,ri;

    nodes[0].p = -1;
    nodes[0].h = 1; 
    forn(i,0,n) {
        cin >> le >> ri;
        le--;ri--;
        nodes[i].dup = false;
        nodes[i].l = le;
        nodes[i].r = ri;
        if (le != -1) {
            nodes[le].p = i;
            //if (nodes[i].h != -1)nodes[l].h = nodes[i].h+1;
        } if (ri != -1) {
            nodes[ri].p = i;
            //if (nodes[i].h != -1) nodes[r].h = nodes[i].h+1;
        }
    }
    order = vi(n);
    reverse_order = vi(n);
    ind = 0;
    inorder(0);
    lesser = v<bool>(n);
    lesser[n-1] = false;
    forr(i,n-2,0) {
        if (tree[order[i]] == tree[order[i+1]]) lesser[i] = lesser[i+1];
        else lesser[i] = tree[order[i]] < tree[order[i+1]];
    }

    form_ans(0,k);
    forn(i,0,n) {
        cout << tree[order[i]];
        if (nodes[order[i]].dup) cout << tree[order[i]];
    }
    //cout << "\n";
}
