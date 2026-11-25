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

    int x; cin >> x;
    while(x > 0) {
        int comb = 0;
        int perm = 0;
        forn(i,0,min(61,x+1)) {
            if (x - i <= 120 && (i <= 20 || i == 50 || (i <= 40 && i % 2 == 0) || i % 3 == 0)) {
                forn(j,max(x-i-60,i),61) {
                    int k = x-i-j;
                    if (k >= j && (j <= 20 || j == 50 || (j <= 40 && j % 2 == 0) || j % 3 == 0) && 
                    (k <= 20 || k == 50 || (k <= 40 && k % 2 == 0) || k % 3 == 0)) {
                        comb++;
                        if (i == j && j == k) perm++;
                        else if (i != j && j != k && i != k) perm += 6;
                        else perm += 3; 
                    }
                }
            }
        }
        if (comb == 0) cout << "THE SCORE OF " << x << " CANNOT BE MADE WITH THREE DARTS.\n";
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << x << " IS " << comb << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << x << " IS " << perm << ".\n";
        }
        forn(i,0,70) cout << "*";
        cout << "\n";
        cin >> x;
    }
    cout << "END OF OUTPUT\n";
}
