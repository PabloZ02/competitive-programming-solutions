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
    forn (t,1,TT+1) {
        v<string> card_suits(52);
        v<int> cards(52);
        forn(i,0,52) {
            string card; cin >> card;
            card_suits[i] = card;
            if (card[0] >= '2' && card[0] <= '9') cards[i] = card[0]-'0';
            else cards[i] = 10;
        }
        int cur_card = 26;
        int y = 0;
        forn(ig,0,3) {
            int x = cards[cur_card];
            y += x;
            cur_card -= (1 + 10 - x);
        }
        int ans = y <= cur_card ? y : y-cur_card+25;
        cout << "Case " << t << ": " <<card_suits[ans] << "\n";
    }
}
