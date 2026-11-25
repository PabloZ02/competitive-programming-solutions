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
    int NEUTRO = 0; 
    
    int f(int a, int b){
        return max(a, b); // cambiar la funcion
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

    int n; cin >> n;
    while(n != 0) {
        int q; cin >> q;
        vi v(n);
        vi freq(n);
        int streak = 1;
        freq[0] = 1;
        cin >> v[0];
        forn(i,1,n) {
            cin >> v[i];
            if (v[i] == v[i-1]) {
                streak++;
            } else {
                streak = 1;
            }
            freq[i] = streak;
        }
        segTree st(freq);
        forn(i,0,q) {
            int l, r;
            cin >> l >> r;
            int lval;
            if (freq[l-1] != 1) {
                int ind = l;
                while(freq[ind] != 1 && ind < n && ind < r) ind++;
                lval = freq[ind-1] - freq[l-1] + 1;
                if (ind == n) cout << lval<< "\n";
                else cout << max(lval, st.query(ind,r)) << "\n";
            } else cout << st.query(l-1,r) << "\n";
        }
        cin >> n;
    }
}
