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
    bool looped = false;
    while (TT--) {
        if (looped) cout << "\n";
        else looped = true;
        int b; int sg; int sb;
        cin >> b >> sg >> sb;
        priority_queue<int> greens;
        priority_queue<int> blues;
        forn(i,0,sg) {
            int green; cin >> green;
            greens.push(green);
        }
        forn(i,0,sb) {
            int blue; cin >> blue;
            blues.push(blue);
        }
            while(greens.size() > 0 && blues.size() > 0) {
            int i = 0;
            vi green_reserve;
            vi blue_reserve;
            while(i < b && greens.size() > 0 && blues.size() > 0) {
                int green = greens.top();
                int blue = blues.top();
                if (green > blue) {
                    green_reserve.pb(green-blue);
                }
                else if (blue > green) {
                    blue_reserve.pb(blue-green);
                }
                greens.pop(); blues.pop();
                i++;     
            }
            forn(i,0,green_reserve.size()) greens.push(green_reserve[i]);
            forn(i,0,blue_reserve.size()) blues.push(blue_reserve[i]);
            }
        if (greens.size() > 0) {
            cout << "green wins\n";
            while(greens.size() > 0) {
                cout << greens.top() << "\n";
                greens.pop();
            }
        }
        else if (blues.size() > 0) {
            cout << "blue wins\n";
            while(blues.size() > 0) {
                cout << blues.top() << "\n";
                blues.pop();
            }
        }
        else cout << "green and blue died\n";
    }
}
