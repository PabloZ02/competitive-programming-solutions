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
        ll n; cin >> n;
        ll traps; cin >> traps;
        ll rolls; cin >> rolls;
        bool finished = false;
        v<bool> has_shortcut(101,false);
        map<int,int> shortcuts;
        forn(i,0,traps) {
            int st,end; cin >> st >> end;
            has_shortcut[st] = true;
            shortcuts[st] = end;
        }
        vi player_pos(n,1);
        ll cur_player = 0;
        ll i = 0;
        while(i < rolls) {
            int next_roll; cin >> next_roll;
            int cur_pos = player_pos[cur_player];
            cur_pos += next_roll;
            if (has_shortcut[cur_pos]) cur_pos = shortcuts[cur_pos];
            if (cur_pos >= 100) {
                i++;
                while(i < rolls) {
                    int ignore; cin >> ignore;
                    i++;
                }
                cur_pos = 100;
            }
            player_pos[cur_player] = cur_pos;
            cur_player = (cur_player + 1) % n; 
            i++;
        }
        forn(i,0,n) {
            cout << "Position of player " << i+1 << " is " << player_pos[i] << ".\n";
        }
    }
}
