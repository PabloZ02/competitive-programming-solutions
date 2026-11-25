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
map<char,char> mirror = {{'A','A'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'}, {'L','J'}, 
{'M','M'}, {'O','O'}, {'S','2'}, {'T','T'}, {'U','U'}, {'V','V'}, {'W','W'}, {'X','X'}, {'Y','Y'},
{'Z','5'}, {'1','1'}, {'2','S'}, {'3','E'}, {'5','Z'}, {'8','8'}};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string text;
    while(getline(cin,text)) {
        bool palindrome = true;
        bool mirrored = true;
        int n = text.size();
        forn(i,0,n/2 + (n%2 != 0)) {
            if (text[i] != text[n-1-i]) palindrome = false;
            if (!mirror.count(text[i]) || mirror[text[i]] != text[n-1-i]) mirrored = false;
        }
        cout << text << " -- ";
        if (palindrome && mirrored) cout << "is a mirrored palindrome.\n";
        else if (palindrome) cout << "is a regular palindrome.\n";
        else if (mirrored) cout << "is a mirrored string.\n";
        else cout << "is not a palindrome.\n";
        cout << "\n";
    }
}
