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
    cin.ignore(); cin.ignore();
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        map<pii,int> pair2int;
        int ind = 1;
        v<v<pair<double,int>>> g;
        string line;
        getline(cin, line);
        stringstream sstr; sstr << line;
        int tmpa,tmpb;
        sstr >> tmpa >> tmpb;
        pii p = {tmpa,tmpb};
        pair2int[p] = 0;
        int tmpc,tmpd;
        pii p2;
        getline(cin,line);
        double ans = 0.0;
        while(line != "") {
            stringstream().swap(sstr);
            sstr << line;
            sstr >> tmpa >> tmpb >> tmpc >> tmpd;
            /*p = {tmpa,tmpb};
            p2 = {tmpc,tmpd};
            if (pair2int.count(p) == 0) {
                pair2int[p] = ind;
                ind++;
            } 
            if (pair2int.count(p2) == 0) {
                pair2int[p2] = ind;
                ind++;
            }*/
            //int ip1 = pair2int[p];
            //int ip2 = pair2int[p2];
            ans += sqrt((tmpa-tmpc)*(tmpa-tmpc) + (tmpb-tmpd)*(tmpb-tmpd)); 
            //g[ip1].pb({d,ip2});
            //g[ip2].pb({d,ip1});
            getline(cin,line);
        }
        ans = round(0.006*ans);
        int m = int (ans)% 60;
        cout << int(ans/60) << ":";
        if (m < 10) cout << "0" << m << "\n";
        else cout << m << "\n";
    }
}
