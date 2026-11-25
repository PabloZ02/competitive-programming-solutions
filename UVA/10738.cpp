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

    vi sv(1000001);
    vi primes;
    for(ll i = 2; i < 1000001; i++) if (sv[i] == 0) {
        primes.pb(i);
        for(ll j = i; j < 1000001; j+=i) sv[j] ++;
    }
    vi M(1000001);
    M[1] = 1;
    forn(i,2,1000001) {
        int curi = 0;
        int curp = 2;
        bool sqf = true;
        while(curp*curp <= i) {
            if (i % (curp*curp) == 0) {
                sqf = false;
                break;
            }
            curp = primes[curi++];
        }
        if (sqf) M[i] = M[i-1] + 1 - 2 * (sv[i] % 2);
        else M[i] = M[i-1];
    }
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;
        cout << setw(8) << right << n << setw(8) << right << M[n]-M[n-1] << setw(8) << right << M[n] << "\n";
    }
}
