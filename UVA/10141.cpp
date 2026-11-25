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

    int n,p;
    cin >> n >> p;
    int rfp = 1;
    bool passed = false;
    while(n != 0) {
        if (passed) cout << "\n"; else passed = true;
        string ignore; 
        forn(i,0,n+1) {
            getline(cin,ignore);
        }
        string best_can; getline(cin,best_can);
        long double best_price; cin >> best_price;
        int best_prop; cin >> best_prop;
        forn(i,0,best_prop+1) getline(cin,ignore);
        forn(i,1,p) {
            string next_can; getline(cin,next_can);
            long double next_price; cin >> next_price;
            int next_prop; cin >> next_prop;
            forn(j,0,next_prop+1) getline(cin,ignore);
            if (next_prop > best_prop || (next_prop == best_prop && next_price < best_price)) {
                best_can = next_can;
                best_price = next_price;
                best_prop = next_prop;
            }
        }
        cout << "RFP #" << rfp << "\n";
        cout <<best_can << "\n";
        cin >> n >> p;
        rfp++;
    }
}
