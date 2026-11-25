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
ll div10 = 10000000000000;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    bitset<1000001> bt;
    bt.set();
    bt[0] = bt[1] = 0;
    vi primes;
    for(ll i = 2; i < 1000001; i++) if (bt[i]) {
        primes.pb(i);
        for(ll j = i*i; j < 1000001; j += i) bt[j] = 0;
    }
    v<ll> ans(1000001);
    v<ll> facs(1000001);
    ans[1] = 1;
    forn(i,2,1000001) {
        int pind = 0;
        int sqrti = floor(sqrt(i));
        int curp = 2;
        int remi = i;
        ll curans = ans[i-1];
        while(curp <= sqrti) {
            if (remi % curp == 0) {
                int count = 0;
                while(remi % curp == 0) {
                    count++;
                    remi /= curp;
                }
                if (facs[curp] < count) {
                    facs[curp]++;
                    curans = (curans * curp);
 

                }
            }
            curp = primes[pind++];
        }
        if (remi > 1) {
            if (facs[remi] == 0) {
                facs[remi]++;

                curans = (curans * remi);
            }
        }
        while(curans % 10 == 0) curans /= 10;
        ans[i] = curans % 10000000;
    }
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;
        cout << ans[n] % 10 << "\n";
    }
}
