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

    string line; cin >> line;
    v<vi> cpos(52, vi(0));
    forn(i,0,line.size()) {
        char c = line[i];
        if (c >= 'A' && c <= 'Z') cpos[c-'A'].pb(i);
        else cpos[c-'a'+26].pb(i);
    }
    int q; cin >> q;
    forn(ig,0,q) {
        string query; cin >> query;
        bool match = true;
        int ind = 0;
        bool ffound = false;
        int find = -1;
        forb(i,0,query.size(),match) {
            int c;
            if(query[i] >= 'A' && query[i] <= 'Z') c = query[i] - 'A';
            else c = query[i] - 'a' + 26;
            auto ans = lower_bound(its(cpos[c]),ind);
            if (ans == cpos[c].end()) match = false;
            else ind = *ans;
            if (!ffound) {
                find = ind;
                ffound = true;
            }
            ind++;
        }
        if (match) {
            cout << "Matched " << find << " " << ind-1 << "\n";
        } else cout << "Not matched\n";
    }
}
