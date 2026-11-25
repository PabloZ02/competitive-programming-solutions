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
vi vec;
const tuple<int,int,int> t = {-1,-1,-1};
int n;
tuple<int,int,int> solve(int i, int left, vector<vector<tuple<int,int,int>>>& M) {
    if (left <= 0) return {0,-left,0};
    else if (i >= n) return {0,INT32_MAX,0};
    else if (get<0>(M[i][left]) != -1) return M[i][left];
    else {
        tuple<int,int,int> ans1 = solve(i+1,left,M);
        tuple<int,int,int> ans2 = solve(i+1,left-vec[i],M);
        ans2 = {get<0>(ans2)+1,get<1>(ans2),get<2>(ans2)+vec[i]};
        if (get<1>(ans1) < get<1>(ans2) || (get<1>(ans1) == get<1>(ans2) && get<0>(ans1) < get<0>(ans2))) {
            M[i][left] = ans1;
        } else M[i][left] = ans2;
        return M[i][left];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        int amount; cin >> amount;
        cin >> n;
        vec.resize(n);
        forn(i, 0, n) cin >> vec[i];
        vector<vector<tuple<int,int,int>>> M(n,vector<tuple<int,int,int>>(amount+1, t));
        tuple<int,int,int> ans = solve(0,amount,M);
        cout << get<2>(ans) << " " << get<0>(ans) << "\n";
    }
}
