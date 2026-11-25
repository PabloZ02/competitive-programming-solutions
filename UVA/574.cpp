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
vi sol;
v<vi> solutions;
bool hassolved;
void solve(int index,vi& v, int tleft) {
    if (tleft == 0) {
        bool found = false;
        forb(i,0,solutions.size(),!found) {
            found = sol == solutions[i];
        }
        if (!found) {
            hassolved = true;
            solutions.pb(sol);
            cout << sol[0];
            forn(i,1,sol.size()) {
                cout << "+" << sol[i];
            } cout << "\n";

        }
    } else if (tleft > 0) {
        forn(i,index,v.size()) {
            sol.pb(v[i]);
            solve(i+1,v,tleft-v[i]);
            sol.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n;
    cin >> t >> n;
    while(n != 0) {
        sol = {};
        solutions = {{}};
        hassolved = false;
        vi v(n);
        forn(i,0,n) cin >> v[i];
        cout << "Sums of " << t << ":\n";
        solve(0,v,t);
        if (!hassolved) cout << "NONE\n";
        cin >> t >> n;
    }
}
