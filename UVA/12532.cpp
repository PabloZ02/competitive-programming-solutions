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

class segTree {
   public:
    vector<int> t;
    int n;
    segTree(vector<int>& v) : n(v.size()) {
        t.resize(2*n);
        forn(i, 0, n) t[i+n] = v[i];
        build();
    }
    // Reemplazar por el neutro de la funcion ejemplo (1-mult, INT_32MAX-min)
    int NEUTRO = 1; 
    
    int f(int a, int b){
        return a*b; // cambiar la funcion
    }

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = f(t[i<<1], t[i<<1|1]);
    }

    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = NEUTRO;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = f(res, t[l++]);
            if (r&1) res = f(res, t[--r]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line; getline(cin, line);
    while(line != "") {
        string ns, ks;
        int ind = 0;
        int n, k;
        while(line[ind] != ' ') {
            ns.pb(line[ind]);
            ind++;
        } ind++;
        while(ind < line.size()) {
            ks.pb(line[ind]);
            ind++;
        }
        n = stoi(ns); k = stoi(ks);
        vi v(n);
        forn(i,0,n) {
            cin >> v[i];
            if (v[i] > 0) v[i] = 1;
            else if (v[i] < 0) v[i] = -1;
        }
        segTree st(v);
        forn(i,0,k) {
            char com;
            cin >> com;
            if (com == 'C') {
                int xi,val;
                cin >> xi >> val;
                if (val > 0) val = 1;
                else if (val < 0) val = -1;
                st.modify(xi-1,val);
            } else {
                int l,r;
                cin >> l >> r;
                int res = st.query(l-1,r);
                if (res == 1) cout << "+";
                else if (res == 0) cout << "0";
                else cout << "-";
            }
        }
        cout << "\n";
        cin.ignore();
        getline(cin,line);
    }
}
