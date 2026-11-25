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
double EPSILON = 1e-6;
// clang-format on
//--------------------------------------
bool deq(double a, double b) {
    return (fabs(a-b) < EPSILON);
}
bool dgeq(double a, double b) {
    return deq(a,b) || isgreater(a,b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    /* int count  = 0;
    for(double a = 0.01; a < 2.12; a += 0.01) {
        for(double b = a; b < 10; b += 0.01) {
            for(double c = b; c < 8.95; c += 0.01) {
                if (isgreater(a*b*c-1,0)) {
                    double d = (a+b+c)/(a*b*c-1.0);
                    if (isgreaterequal(d,c) && deq(d*100.0-floor(d*100.0),0.0) && deq(a+b+c+d,a*b*c*d) && isgreaterequal(20.0,a+b+c+d)) {
                        cout << setprecision(2) << fixed << a << " " << b << " " << c << " " << d << "\n";
                        count++;
                    }
                }
            }
        }
    }
    cout << count << "\n"; */

    int count  = 0;
    for(int a = 1; a < 212; a++) {
        for(int b = a; 3*b+a < 2001; b++) {
            for(int c = b; a+b+2*c < 2001; c++) {
                ll y = (ll) a*b*c;
                ll s = a+b+c;
                if (y-1000000 < 1) continue;
                int d = (s*1000000)/(y-1000000);
                if ((s*1000000)%(y-1000000) == 0 && d >= c && s+d <= 2000) {
                    printf("%d.%02d %d.%02d ", a/100, a%100, b/100, b%100);
                    printf("%d.%02d %d.%02d\n", c/100, c%100, d/100, d%100);
                }
            }
        }
    }
}
