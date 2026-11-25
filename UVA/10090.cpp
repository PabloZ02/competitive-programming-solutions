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
ll n, c1, x, c2, y;
ll d;
void eeu(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    eeu(b, a % b);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cin >> c1 >> a >> c2 >> b;
        bool swapped = false;
        eeu(a, b);
        if (n % d != 0)
            cout << "failed\n";
        else
        {
            ll mult = n / d;
            x *= mult;
            y *= mult;
            if (double (b) / c2> double (a) / c1)
            {
                ll tv = a;
                ll ti = x;
                ll tc = c1;
                a = b;
                c1 = c2;
                x = y;
                b = tv;
                c2 = tc;
                y = ti;
                swapped = true;
            }
            if (y < 0)
            {
                x -= (b / d) * ceil((double)(-y * d) / double(a));
                y += (a / d) * ceil((double)(-y * d) / double(a));
                if (x < 0)
                    cout << "failed\n";
                else if (swapped)
                    cout << y << " " <<  x << "\n";
                else
                    cout <<x << " " <<  y << "\n";
            }
            else
            {
                x += (b / d) * floor(double(y * d) / double(a));
                y -= (a / d) * floor(double(y * d) / double(a));
                if (x < 0)
                    cout << "failed\n";
                else if (swapped)
                    cout << y << " " << x << "\n";
                else
                    cout << x << " " << y << "\n";
            }
        }
    }
}
