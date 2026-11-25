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
        int n; cin >> n;
        int s; int q; cin >> s >> q;
        int remaining = 0;
        vector<queue<int>> stations(n);
        forn(i,0,n) {
            int qi; cin >> qi;
            remaining += qi;
            queue<int> cargo;
            forn(j,0,qi) {
                int next_cargo; cin >> next_cargo;
                cargo.push(next_cargo);
            }
            stations[i] = cargo; 
        }
        stack<int> carrier;
        int station = 0;
        int minutes = 0;
        bool passed = false;
        while (remaining > 0) {
            if (passed) minutes += 2;
            else passed = true;
            while(!carrier.empty()) {
                int next_cargo = carrier.top();
                if (next_cargo == station+1) {
                    
                    carrier.pop();
                    minutes++;
                    remaining--;
                }
                else if (stations[station].size() < q) {
                    stations[station].push(next_cargo);
                    carrier.pop();
                    minutes++;
                }
                else break;
            }
            while(!stations[station].empty() && carrier.size() < s) {
                int next_cargo = stations[station].front();
                carrier.push(next_cargo);
                stations[station].pop();
                minutes++;
            }
            station = (station+1) % n;
        }
        cout << minutes << "\n";
    }
}
