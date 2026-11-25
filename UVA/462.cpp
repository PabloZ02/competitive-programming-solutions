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

int suit(char s) {
    if (s == 'S') return 0;
    else if (s == 'H') return 1;
    else if (s == 'D') return 2;
    return 3;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string card;
    
    
    while(cin >> card) {
        vector<string> cards(13);
        cards[0] = card;
        forn(i,1,13) {cin >> card; cards[i] = card;} 
        int points = 0;
        int extra_points = 0;
        int stopped_count = 0;
        vector<bool> has_king = {false,false,false,false};
        vector<bool> has_queen = {false,false,false,false};
        vector<bool> has_jack = {false,false,false,false};
        vector<bool> has_ace = {false,false,false,false};
        vector<int> card_amounts = {0,0,0,0};

        forn(i,0,13) {
            int suitval = suit(cards[i][1]);
            char cardval = cards[i][0];
            card_amounts[suitval]++;
            if (cardval == 'A') {
                points += 4;
                has_ace[suitval] = true;
            }
            else if (cardval == 'K') {
                points += 3;
                has_king[suitval] = true;
            }
            else if (cardval == 'Q') {
                points += 2;
                has_queen[suitval] = true;
            }
            else if (cardval == 'J') {
                points += 1;
                has_jack[suitval] = true;
            }
        }
        forn(i,0,4) {
            if (has_king[i] && card_amounts[i] == 1) points--;
            if (has_queen[i] && card_amounts[i] <= 2) points--;
            if (has_jack[i] && card_amounts[i] <= 3) points--;
            
            if (card_amounts[i] == 2) extra_points++;
            else if (card_amounts[i] < 2) extra_points += 2;

            if (has_ace[i] || (has_king[i] && card_amounts[i] > 1) || (has_queen[i] && card_amounts[i] > 2)) {
                stopped_count++;
            }
            
        }
        if (points >= 16 && stopped_count == 4) {
            cout << "BID NO-TRUMP\n";
        }
        else if (points + extra_points >= 14) {
            char suit_print;
            int maximum = 0;
            int maxind;
            forn(i,0,4) {
                if (card_amounts[i] > maximum) {
                    maximum = card_amounts[i];
                    maxind = i;
                }
            }
            if (maxind == 0) suit_print = 'S';
            else if (maxind == 1) suit_print = 'H';
            else if (maxind == 2) suit_print = 'D';
            else suit_print = 'C';
            cout << "BID " << suit_print << "\n";
        }
        else cout << "PASS\n";
        
    }
}
