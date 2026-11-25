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

enum {LEFT, RIGHT};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        int n; int t; int m;
        cin >> n >> t >> m;
        int minutes = 0;
        queue<pii> cars_l;
        queue<pii> cars_r;
        int dir = LEFT;
        vi times(m);
        forn(i,0,m) {
            int car; cin >> car;
            string direc; cin >> direc;
            if (direc == "left") cars_l.push({car,i});
            else cars_r.push({car,i});
        }
        while(cars_l.size() > 0 || cars_r.size() > 0) {
            if (dir == LEFT) {
                if (!cars_l.empty() && cars_l.front().first <= minutes) {
                    int cars = 0;
                    while(!cars_l.empty() && cars_l.front().first <= minutes && cars < n) {
                        cars++;
                        times[cars_l.front().second] = minutes+t;
                        cars_l.pop();
                    }
                    minutes += t;
                    dir = RIGHT;
                }
                else if (!cars_l.empty()) {
                    if (!cars_r.empty() && cars_r.front().first < cars_l.front().first) {
                        minutes = max(minutes, cars_r.front().first) + t;
                        dir = RIGHT;
                    }
                    else minutes = max(minutes, cars_l.front().first);
                }
                else {
                    minutes = max(minutes, cars_r.front().first) + t;
                        dir = RIGHT;
                }
            }
            else if (dir == RIGHT) {
                if (!cars_r.empty() && cars_r.front().first <= minutes) {
                    int cars = 0;
                    while(!cars_r.empty() && cars_r.front().first <= minutes && cars < n) {
                        cars++;
                        times[cars_r.front().second] = minutes+t;
                        cars_r.pop();
                    }
                    minutes += t;
                    dir = LEFT;
                }
                else if (!cars_r.empty()) {
                    if (!cars_l.empty() && cars_l.front().first < cars_r.front().first) {
                        minutes = max(cars_l.front().first,minutes) + t;
                        dir = LEFT;
                    }
                    else minutes = max(minutes, cars_r.front().first);
                }
                else {
                    minutes = max(minutes,cars_l.front().first) + t;
                        dir = LEFT;
                }
            }
        }
        forn(i,0,times.size()) {
            cout << times[i] << "\n";
        }
    }
}
