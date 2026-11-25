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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    forn (tt,1,TT+1) {
        string line;
        cin >> line;
        int ind = 1;
        string var1;
        while(line[ind] != '+') {
            var1.pb(line[ind]);
            ind++;
        } ind++;
        string var2;
        while(line[ind] != ')') {
            var2.pb(line[ind]);
            ind++;
        } ind += 2;
        string ns;
        while(ind < line.size()) {
            ns.pb(line[ind]);
            ind++;
        }
        int n = stoi(ns);
        v<v<ll>> C(n+1, v<ll>(n+1));
        C[0][0] = 1;
        forn(i,1,n+1) {
            C[i][0] = 1;
            C[i][i] = 1;
            forn(j,1,i) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        cout << "Case " << tt << ": " << var1;
        if(n > 1) cout << "^" << n;
        forn(i,1,n) {
            cout << "+" << C[n][i] << "*" << var1;
            if (n-i > 1) cout <<"^" << n-i; 
            cout << "*" << var2;
            if(i > 1) cout <<"^" << i;
        }
        cout << "+" << var2;
        if (n > 1) cout << "^" << n <<"\n";
        else cout << "\n";
    }
}
