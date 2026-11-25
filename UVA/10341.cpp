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
const double EulerConstant = std::exp(1.0);
vector<double> paramd(6);
double eps = 1e-9;
double solve(double x) {
    return paramd[0]*pow(EulerConstant,-x) + paramd[1]*sin(x) + paramd[2]*cos(x)+paramd[3]*tan(x)+
    paramd[4]*x*x+paramd[5];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string parameters;
    while(getline(cin,parameters)) {
        if(parameters == "") break;
        vector<string> params(6);
        int ind = 0;
        forn(i,0,parameters.size()) {
            if(parameters[i] == ' ') {
                ind++;
            }
            else {
                params[ind] += parameters[i];
            }
        }
        forn(i,0,6) {
            paramd[i] = stod(params[i]);
        }
        double low = 0.0;
        double high = 1.0;
        double x1 = solve(low);
        double x2 = solve(high);
        double ans;
        if (isgreater(eps,fabs(x1))) {
            ans = low;
        } else if (isgreater(eps,fabs(x2))) {
            ans = high;
        }
        else if (isgreater(x2,0.0) && isgreater(0.0,x1)) {
            while(fabs(high-low) > eps) {
            double mid = (high + low) / 2.0;
            if (isgreater(solve(mid),0)) high = mid;
            else low = mid;
            }
            ans = low;
        }
        else if (isgreater(x1,0.0) && isgreater(0.0,x2)) {
        while(fabs(high-low) > eps) {
            double mid = (high + low) / 2.0;
            if (isgreater(solve(mid),0)) low = mid;
            else high = mid;
            }
            ans = low;
        }
        else ans = -1.0;
        double fz = -0.5;
        if (!isgreater(fz,ans)) cout << setprecision(4) << fixed << ans << "\n";
        else cout << "No solution\n";

    }
}
