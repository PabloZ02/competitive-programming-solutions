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

    int TT;
    cin >> TT;
    forn(t,1,TT+1) {
        cout << "Case " << t <<": ";
        int n; cin >> n;
        vi v(n);
        forn(i, 0, n) {
            cin >> v[i];
        }
        int maxv = v[v.size()-1];
        int minv = v[0];
        int k = maxv;
        while(maxv-minv > 1) {
            k = (maxv+minv)/2;
            bool could_pass = true;
            int cur_height = k;
            int tempk = k;
            forb(i,0,n,could_pass) {
                if (v[i] > cur_height) could_pass = false;
                else {
                    if (cur_height == v[i]) tempk--;
                    cur_height = v[i]+tempk;
                }
            }
            if (could_pass) maxv = k;
            else minv = k;
        }
        bool could_pass = true;
        int cur_height = k-1;
        int tempk = k-1;
        forb(i,0,n,could_pass) {
            if (v[i] > cur_height) could_pass = false;
            else {
                if (cur_height == v[i]) tempk--;
                cur_height = v[i]+tempk;
            }
        }
        bool could_pass2 = true;
        cur_height = k;
        tempk = k;
        forb(i,0,n,could_pass2) {
            if (v[i] > cur_height) could_pass2 = false;
            else {
                if (cur_height == v[i]) tempk--;
                cur_height = v[i]+tempk;
            }
        }
        if (could_pass) cout << k-1 << "\n";
        else if (could_pass2) cout << k << "\n";
        else cout << k+1 << "\n";
    }
}
