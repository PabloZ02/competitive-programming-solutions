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
    bitset<10000001> sv;
    sv.set();
    sv[0] = sv[1] = 0;
    vi primes;
    for(ll i = 2; i < 10000001; i++) if (sv[i]) {
        primes.pb(i);
        for(ll j = i*i; j < 10000001; j += i) sv[j] = 0;
    }

    int TT;
    cin >> TT;
    while (TT--) {
        int a,b;
        cin >> a >> b;
        if (b % a != 0) cout << "NO SOLUTION\n";
        else {
            map<int,int> facts;
            int pind = 0;
            int curp = 2;
            int sqrtb = floor(sqrt(b));
            int ans = b;
            while(curp <= sqrtb) {
                if (b % curp == 0) {
                    int count = 0;
                    while(b % curp == 0) {
                        count++;
                        b /= curp;
                    }
                    facts[curp] = count;
                }
                curp = primes[pind++];
            }
            if (b > 1) facts[b] = 1;
            pind = 0;
            curp = 2;
            int sqrta = floor(sqrt(a));
            while(curp <= sqrta) {
                if (a % curp == 0) {
                    int count = 0;
                    while(a % curp == 0) {
                        count++;
                        a /= curp;
                    }
                    if (facts.count(curp) > 0 && facts[curp] == count) ans /= pow(curp,count);
                }
                curp = primes[pind++];
            }
            if (a > 1 && facts.count(a) > 0 && facts[a] == 1) ans /= a;
            cout << ans << "\n";
        }
    }
}
