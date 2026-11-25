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
int overfl = 262144;
map<char,int> char2int = {{'V',0}, {'U',1}, {'C',2},{'D',3}};
int str2int(string s) {
    int ans = 0;
    int f = 1;
    forr(i,s.size()-1,0) {
        ans += char2int[s[i]]*f;
        f *= 4;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    cout << "COWCULATIONS OUTPUT\n";
    while (TT--) {
        string ns1,ns2;
        cin >> ns1 >> ns2;
        int n1 = str2int(ns1);
        int n2 = str2int(ns2);
        char cmnd;
        forn(i,0,3) {
            cin >> cmnd;
            if (cmnd == 'A') {
                n2 = (n2 + n1) % overfl;
            } else if (cmnd == 'R') n2 /= 4;
            else if (cmnd == 'L') n2 = (n2 * 4) % overfl;
        }
        string ns3;
        cin >> ns3;
        printb(n2 == str2int(ns3));
    }
    cout << "END OF OUTPUT\n";
}
