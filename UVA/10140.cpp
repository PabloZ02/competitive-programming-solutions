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
bitset<2147483649>primes;
ll max_sieve = sqrt(2147483648)+1;
v<ll> all_p;

bool is_prime(ll i) {
    if (i < max_sieve) return primes[i];
    else {
        forn(j,0,all_p.size()) {
            if (i % all_p[j] == 0) return false;
        }
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    primes.set();
    primes[0] = primes[1] = 0;
    for(ll i = 2; i < max_sieve; i++) if (primes[i]) {
        all_p.pb(i);;
        for(ll j = i*i; j < max_sieve; j += i) primes[j] = 0;
    }
    string line;
    while(getline(cin,line)) {
        stringstream sst(line);
        ll l,u; 
        sst >> l >> u;
        int found = 0;
        pii minp, maxp;
        int mind,maxd;
        int lastp;
        for(ll i = l; i < u+1; i++) {
            if (is_prime(i)) {
                if (found == 0) found++;
                else {
                    int d = i - lastp;
                    if (found == 1) {
                        found++;
                        minp = maxp =  {lastp,i};
                        mind = maxd = d;
                    } else {
                        if (d < mind) {
                            mind = d;
                            minp = {lastp,i};
                        } else if (d > maxd) {
                            maxd = d;
                            maxp = {lastp,i};
                        }
                    }
                }
                lastp = i;
            }
        }
        if (found < 2) cout << "There are no adjacent primes.\n";
        else {
            cout << minp.first << "," << minp.second << " are closest, ";
            cout << maxp.first << "," << maxp.second << " are most distant.\n";
        }
    }
}
