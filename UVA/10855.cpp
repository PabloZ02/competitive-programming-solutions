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

    int N,n;
    cin >> N >> n;
    while(N != 0) {
        vector<string> big_square(N);
        vector<string> small_square(n);
        forn(i,0,N) cin >> big_square[i];
        forn(i,0,n) cin >> small_square[i];
        int rot = 0;
        vi rot_matches(4);
        while(rot < 4) {
            forn(i,0,N-n+1) {
                forn(j,0,N-n+1) {
                    bool match = true;
                    forb(a,0,n,match) {
                        forb(b,0,n,match) {
                            match = small_square[a][b] == big_square[i+a][j+b];
                        }
                    }
                    rot_matches[rot] += match;
                }
            }
            if (rot != 3) {
                vector<string> rot_square = small_square;
                forn(i,0,n) {
                    forn(j,0,n) {
                        rot_square[i][j] = small_square[n-j-1][i];
                    }
                }
                small_square = rot_square;
            }
            rot++;
        }
        cout << rot_matches[0] << " " << rot_matches[1] << " " << rot_matches[2] << " " << rot_matches[3] << "\n";
        cin >> N >> n;
    }
}
