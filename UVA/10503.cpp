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
int n, m;
vector<pii> dominoes(20);
vector<pii> pieces(20);

bool solve(int i,vector<bool>& used) {
    if (i == n+1) return dominoes[i-1].second == dominoes[i].first;
    else {
        bool found = false;
        forb(j,0,m,!found) {
            if (!used[j] && pieces[j].first == dominoes[i-1].second) {
                used[j] = true;
                dominoes[i] = pieces[j];
                found = solve(i+1,used);
                used[j] = false;
            }
            else if (!used[j] && pieces[j].second == dominoes[i-1].second) {
                used[j] = true;
                dominoes[i] = {pieces[j].second, pieces[j].first};
                found = solve(i+1,used);
                used[j] = false;
            }
        }
        return found;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while(n != 0) {
        cin >> m;
        int frst, snd;
        cin >> frst >> snd;
        dominoes[0] = {frst,snd};
        cin >> frst >> snd;
        dominoes[n+1] = {frst,snd};
        forn(i,0,m) {
            cin >> frst >> snd;
            pieces[i] = {frst,snd};
        }
        vector<bool> used(m);
        printb(solve(1,used));
        cin >> n;
    }
}
