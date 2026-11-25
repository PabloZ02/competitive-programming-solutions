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

    string line;
    string ign;
    while(1) {
        getline(cin,line);
        if (line == "0 Fuel consumption 0") break;
        v<string> events;
        events.pb(line);
        while(1) {
            getline(cin,line);
            events.pb(line);
            if (line[line.size()-1] == 'l') break;
        }
        double max_fuel = 0.0;
        int leaks = 0;
        stringstream sstr(events[0]);
        string cur;
        forn(i,0,3) sstr >> ign;
        int fc; sstr >> fc;
        int lastpos = 0;
        double fuel_cons = 0.0;
        forn(i,1,events.size()) {
            stringstream evstr(events[i]);
            int pos; evstr >> pos;
            fuel_cons += (pos-lastpos)*fc/100.0 + (pos-lastpos)*leaks;
            lastpos = pos;
            string event; evstr >> event;
            if (event == "Fuel") {
                evstr >> ign;
                evstr >> fc;
            }
            else if (event == "Leak") leaks++;
            else if (event == "Mechanic") leaks = 0;
            else {
                maxeq(max_fuel,fuel_cons);
                fuel_cons = 0;
            }
        }
        cout << fixed << setprecision(3) << max_fuel << "\n";
    }
}
