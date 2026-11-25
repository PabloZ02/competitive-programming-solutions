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
vi sol;
int max_sum;
int solve(int i,int j, vi& sol_t, int n, int t, int sum, vi& v) {
    if (sum <= n && i <= t && j <= t) {
        if (sum > max_sum) {
            max_sum = sum;
            forn(k,0,i) {
                sol[k] = sol_t[k];
            } if (i < t) sol[i] = 0;
        }
        forn(k,j+1,t) {
            sol_t[i] = v[k];
            solve(i+1,k,sol_t,n,t,sum+v[k],v);
        }
        return max_sum;

    } 
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin,line);
    while(line != "") {
        string ns; int ind = 0;
        while(line[ind] != ' ') {
            ns.pb(line[ind]);
            ind++;
        } ind++;
        int n = stoi(ns);
        string ts;
        while(line[ind] != ' ') {
            ts.pb(line[ind]);
            ind++;
        } ind++;
        int t = stoi(ts);
        vi v(t);
        forn(i,0,t) {
            string vs;
            while(ind < line.size() && line[ind] != ' ') {
                vs.pb(line[ind]);
                ind++;
            } ind++;
            v[i] = stoi(vs);
        }
        sol.resize(t);
        forn(i,0,t) sol[i] = 0;
        vi cur_sol(t,0);
        max_sum = 0;
        solve(0,-1,cur_sol,n,t,0,v);
        int i = 0;
        while(i < sol.size() && sol[i] != 0) {
            cout << sol[i] << " ";
            i++;
        }
        cout << "sum:" << max_sum << "\n";
        getline(cin,line);
    }
}
