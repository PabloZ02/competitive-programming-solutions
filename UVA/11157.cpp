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
    forn(ig,1,TT+1) {
        cout << "Case " << ig << ": ";
        int n, d;
        cin >> n >> d;
        vector<pii> stones(n);
        string stone; 
        forn(i,0,n) {
            cin >> stone;
            int kind = stone[0] == 'B' ? 0 : 1;
            string nums;
            forn(j,2,stone.size()) nums += stone[j];
            stones[i] = {stoi(nums), kind};
        }
        bool skip = false;
        int mindist = 0;
        int cur = 0;
        forn(i,0,n) {
            if (stones[i].second == 0) {
                maxeq(mindist, stones[i].first-cur);
                cur = stones[i].first;
            } else if (skip == false) {
                maxeq(mindist, stones[i].first-cur);
                cur = stones[i].first;
                stones[i].second = 2;
                skip = true;
            } else skip = false;
        }
        maxeq(mindist, d-cur);
        cur = d;
        forr(i,n-1,0) {
            if (stones[i].second < 2) {
                maxeq(mindist, cur-stones[i].first);
                cur = stones[i].first;
            }
        }
        maxeq(mindist,cur);
        cout << mindist << "\n";
    }
}
