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

    bitset<32768> sv;
    sv.set();
    sv[0] = sv[1] = 0;
    vi primes;
    for(ll i = 2; i < 32768; i++) if (sv[i]) {
        primes.pb(i);
        for(ll j = i*i; j < 32768; j += i) sv[j] = 0;
    }
    string line;
    while(1) {
        getline(cin,line);
        if(line == "0") break;
        stringstream sst(line);
        int n,p,e;
        n = 1;
        while(sst >> p) {
            sst >> e;
            n *= pow(p,e);
        }
        n--;
        v<pii> facts;
        int pind = 0;
        int curp = primes[0];
        int sqrtn = floor(sqrt(n));
        while(curp <= sqrtn) {
            if (n % curp == 0) {
                facts.pb({curp,1});
            
                n /= curp;
                while(n % curp == 0) {
                    facts[facts.size()-1].second++;
                    n /= curp;
                }
            }
            curp = primes[pind++];
        }
        if (n != 1) facts.pb({n,1});
        cout << facts[facts.size()-1].first << " " << facts[facts.size()-1].second;
        forr(i,facts.size()-2,0) cout << " " << facts[i].first << " " << facts[i].second;
        cout << "\n";
    }
}
