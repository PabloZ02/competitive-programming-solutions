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
void transfor(vector<string>& s) {
    vector<string> scopy = s;
    forn(i,0,3) {
        forn(j,0,3) {
            int sum = 0;
            if (i > 0) {
                sum+= (s[i-1][j]-'0');
            }
            if (i < 2) {
                sum+= (s[i+1][j]-'0');
            }
            if (j > 0) {
                sum += (s[i][j-1] -'0');
            }
            if (j < 2) {
                sum += (s[i][j+1] - '0');
            }
            sum %= 2;
            scopy[i][j] = sum + '0';
        }
    }
    s = scopy;
}

bool not_null(vector<string>s) {
    bool res = false;
    forn(i,0,3) {
        forn(j,0,3) {
            res |= s[i][j] - '0';
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        
        int i = -1;
        vector<string> s(3);
        forn(i,0,3) {
            string ss; cin >> ss;
            s[i] = ss;
        }
        while(not_null(s)) {
            i++;
            transfor(s);
            
        }
        cout << i << "\n";
    }
}
