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
int n;
vector<bool>used(17);
void solve(vector<bool>& primes, vi& ans, int i) {
    if (i == n-1) {
        if (primes[ans[i] + ans[0]]) {
        cout << "1";
        forn(j,1,n) cout << " " << ans[j];
        cout << "\n";
        }
    } else {
        forn(j,2,n+1) {
            if (!used[j] && primes[ans[i] + j]) {
                ans[i+1] = j;
                used[j] = true;
                solve(primes,ans,i+1);
                used[j] = false;
            }
        }
    }
}

bool is_prime(int n) {
    if (n ==3 || n == 2) return true;
    int nsqrt = sqrt((float)n);
    bool prime = true;
    forb(i,2,nsqrt+1,prime) {
        prime &= (n % i != 0);
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string ns;
    int casen = 1;
    bool passed = false;
    while(getline(cin,ns)) {
        if (ns == "") break;
        if (passed) cout << "\n";
        else passed = true;
        cout << "Case " << casen << ":\n";
        casen++;
        n = stoi(ns);
        vi v(n);
        forn(i,0,n) v[i] = i+1;
        vector<bool> primes(2*n);
        forn(i,3,2*n) primes[i] = is_prime(i);
        vi ans(n); ans[0] = 1;
        solve(primes,ans,0);
        forn(i,0,17) used[i] = false;
    }
}
