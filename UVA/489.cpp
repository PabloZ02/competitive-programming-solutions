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

    int round;
    cin >> round;
    while(round != -1) {
        vector<bool> letters(26);
        int distinct = 0;
        string word; cin >> word;
        forn(i,0,word.size()) {
            if (letters[word[i] - 'a'] == false) {
                distinct++;
                letters[word[i] - 'a'] = true;
            }
        }
        string guess; cin >> guess;
        int i = 0; int tries = 7;
        bool success = false;
        while(i < guess.size() && tries > 0 && distinct > 0) {
            if (letters[guess[i] - 'a'] == true) {
                letters[guess[i] - 'a'] = false;
                distinct--;
                if (distinct == 0) success = true;
            }
            else tries--;
            i++;
        }
        cout << "Round " << round << "\n";
        if (success) {
            cout << "You win.\n";
        }
        else if (tries == 0) {
            cout << "You lose.\n";
        }
        else {
            cout << "You chickened out.\n";
        }

        cin >> round;
    }
}
