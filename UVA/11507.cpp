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

    int l; cin >> l;
    while (l != 0) {
        string cur_dir = "+x";
        string x_dir = "+x";
        forn(i,0,l-1) { 
            string dir; cin >> dir;
            if (cur_dir == "+x") {
                if (dir != "No") cur_dir = dir;
            }
            else if (cur_dir == "-x") {
                if (dir == "+z") cur_dir = "-z";
                else if (dir == "-z") cur_dir = "+z";
                else if (dir == "+y") cur_dir = "-y";
                else if (dir == "-y") cur_dir = "+y";
            }
            else if (cur_dir == "+z") {
                if (dir == "+z") {cur_dir = "-x"; x_dir = "-x";}
                else if (dir == "-z") {cur_dir = "+x";  x_dir = "+x";}
            }
            else if (cur_dir == "-z") {
                if (dir == "-z") {cur_dir = "-x"; x_dir = "-x";}
                else if (dir == "+z") {cur_dir = "+x";  x_dir = "+x";} 
            }
            else if (cur_dir == "+y") {
                if (dir == "+y") {cur_dir = "-x"; x_dir = "-x";}
                else if (dir == "-y") {cur_dir = "+x";  x_dir = "+x";} 
            }
            else if (cur_dir == "-y") {
                if (dir == "-y") {cur_dir = "-x"; x_dir = "-x";}
                else if (dir == "+y") {cur_dir = "+x";  x_dir = "+x";} 
            }
        }
        cout << cur_dir << "\n";
        cin >> l;
    }
}
