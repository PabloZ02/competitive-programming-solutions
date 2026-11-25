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
    while (TT--) {
        int p,c;
        cin >> p >> c;
        vi prod(p);
        vi cons(c);
        forn(i,0,p) cin >> prod[i];
        forn(i,0,c) cin >> cons[i];
        sortv(prod);
        sortv(cons);
        int consind = 0;
        if (c == 0 && p == 0) {
            cout << "0 0" << "\n";
        }
        else if (c == 0) {
            cout << prod[p-1] << " 0" << "\n";
        }
        else if (p == 0) {
            cout <<  "0 0" << "\n";
        }
        else {
            int ansval = 0;
            int ansangry = p;
            forn(pind,0,p) {
                while(consind < c && cons[consind] < prod[pind]) consind++;
                int ang = p-(pind+1) + (consind);
                if (ang < ansangry) {
                    ansangry = ang;
                    ansval = prod[pind];
                }
            }
            cout << ansval << " " << ansangry << "\n";
        }

    }
}
