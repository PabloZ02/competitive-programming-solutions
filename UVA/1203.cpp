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


struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second || (a.second == b.second && a.first > b.first);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vi periods(3001,0);
    priority_queue<pii, vector<pii>, myComp> argus;
    string reg; cin >> reg;
    while(reg != "#") {
        int q, p;
        cin >> q >> p;
        pii pq = {q,p};
        argus.push(pq);
        periods[q] = p;
        cin >> reg;
    }
    int k; cin >> k;
    forn(ig,0,k) {
        pii pq = argus.top();
        cout << pq.first << "\n";
        argus.pop();
        argus.push({pq.first,pq.second+periods[pq.first]});
    }
}
