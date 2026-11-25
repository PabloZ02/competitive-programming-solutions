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

    string ns;
    while(getline(cin,ns)) {
        
        int n = stoi(ns);
        int m; cin >> m;
        v<bool> awake(n);
        int cur_area = 0;
        vi areas(27,-1);
        v<v<int>> g(n, vi(0));
        string aw; cin >> aw;
        forn(i,0,3) {
            areas[aw[i]-'A'] = cur_area;
            cur_area++;
            awake[areas[aw[i]-'A']] = true;
        }
        string edge;
        forn(i,0,m) {
            cin >> edge;
            if (areas[edge[0]-'A'] == -1) {
                areas[edge[0]-'A'] = cur_area;
                cur_area++;
            }
            if (areas[edge[1]-'A'] == -1) {
                areas[edge[1]-'A'] = cur_area;
                cur_area++;
            }
            int a = areas[edge[0]-'A'];
            int b = areas[edge[1]-'A'];
            g[a].pb(b);
            g[b].pb(a);
        }
        int years = 0;
        int asleep = n-3;
        bool awaking = true;
        while(asleep > 0 && awaking) {
            awaking = false;
            vi awakened(0);
            forn(i,0,n) {
                if (!awake[i]) {
                    int awake_n = 0;
                    forn(j,0,g[i].size()) {
                        awake_n += awake[g[i][j]];
                    }
                    if (awake_n >= 3) {
                        awakened.pb(i);
                        awaking = true;
                        asleep--;
                    }
                }
            }
            forn(i,0,awakened.size()) {
                awake[awakened[i]] = true;
            }
            years++;
        }
        if (!awaking) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << years <<", YEARS\n";

        cin.ignore(); 
        cin.ignore();
    }
}
