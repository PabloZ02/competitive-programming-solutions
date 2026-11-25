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
ll x,y,d;
void eeu(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    eeu(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll a,b;
    string line;
    while(getline(cin,line)) {
        stringstream sstr(line);
        sstr >> a >> b;
        bool swapped = false;
        if (a == 0) {
            cout << a << " " << int(b != 0) << " " << b << "\n";
            continue;
        }
        else if (b == 0) {
            cout << "1" << " " << b << " " << a << "\n";
            continue;
        }
        else if (a == b) {
            cout << "0 1 " << a << "\n";
            continue;
        }
        eeu(a,b);
        if (y > x) {
            ll t = a;
            ll tv = x;
            x = y;
            a = b;
            b = t;
            y = tv;
            swapped = true;
        }
        if (x < 0) {
            x += ceil(double(-x*d)/double(b)) * b/d;
            y -=  ceil(double(-x*d)/double(b)) * a/d;
        }
        else {
            x -= floor(double(x*d)/double(b)) * b / d;
            y += floor(double(x*d)/double(b)) * a/d;
        }
        ll x1 = x - b/d;
        ll y1 = y + a/d;
        if (abs(x1) + abs(y1) < x + abs(y) || (abs(x1) + abs(y1) == x + abs(y) && !swapped)) {
            cout << x1 << " " << y1 << " ";
        } else if (!swapped) cout << x << " " << y << " ";
        else cout << y << " " << x << " ";
        cout << d << "\n";
    }

}
