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

    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    while( a!= 0) {
        v<bool> played(54);
        played[a] = true; played[b] = true;
        played[c] = true; played[x] = true;
        played[y] = true;
        int sismax = max(a,max(b,c));
        int sismin = min(a,min(b,c));
        int sismid;
        if ((a <= b && a >= c) || (a >= b && a <= c)) sismid = a;
        else if ((b <= a && b >= c) || (b >= a && b <= c)) sismid = b;
        else sismid = c;
        if (x > sismax && y > sismax) {
            int min = 1;
            while(played[min]) min++;
            cout << min << "\n";
        } else if  (x > sismax || y > sismax) {
            int child_min = min(x,y);
            int maxim;
            if (child_min > sismid) {
                maxim = sismid;    
            } else {
                maxim = sismax;
            }
            while(played[maxim]) maxim++;
            if (maxim > 52) cout << "-1\n";
            else cout << maxim << "\n";
        } else if (x > sismid && y > sismid) {
            int mid = sismid;
            while(played[sismid]) sismid++;
            if (sismid > 52) cout << "-1\n";
            else cout << sismid << "\n";
        } else cout << "-1\n";

        cin >> a >> b >> c >> x >> y;
    }
}
