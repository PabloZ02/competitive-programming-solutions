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
    forn(ig,1,TT+1) {
        cout << "Case " << ig << ":\n";
        vector<tuple<string,int,int>> players(10);
        forn(i,0,10) {
            string player; int at; int def;
            cin >> player >> at >> def;
            players[i] = {player,at,def};
        }
        sortv(players);
        vector<string> order(10);
        int maxat = 0;
        int maxdef = 0;
        forn(a,0,6) {
            forn(b,a+1,7) {
                forn(c,b+1,8) {
                    forn(d,c+1,9) {
                        forn(e,d+1,10) {
                            int at = 0;
                            vector<string> attackers;
                            int def = 0;
                            vector<string> defenders;
                            forn(i,0,10) {
                                if (i != a && i != b && i != c && i != d && i != e) {
                                    def += get<2>(players[i]);
                                    defenders.pb(get<0>(players[i]));
                                } else {
                                    at +=get<1>(players[i]);
                                    attackers.pb(get<0>(players[i]));
                                }
                            }
                            if (at > maxat || (at == maxat && def > maxdef)) {
                                maxat = at; maxdef = def;
                                forn(i,0,5) order[i] = attackers[i];
                                forn(i,0,5) order[i+5] = defenders[i];
                            }
                        }
                    }
                }
            }
        }
        cout << "(" << order[0];
        forn(i,1,5) cout << ", " << order[i];
        cout << ")\n";
        cout << "(" << order[5];
        forn(i,6,10) cout << ", " << order[i];
        cout << ")\n";
    }
}
