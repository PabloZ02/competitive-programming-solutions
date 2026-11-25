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

    
    int n; cin >> n;
    while(n != 0) {
        v<v<pair<ll,int>>> g_y;
        v<v<pair<ll,int>>> g_m;
        vi char2int(30,-1);
        v<char> int2char;
        int ind = 0;
        forn(i,0,n) {
            char m,w,a,b;
            ll c;
            cin >> m >> w >> a >> b >> c;
            if (char2int[a-'A'] == -1) {
                char2int[a-'A'] = ind;
                int2char.pb(a);
                ind++;
                g_m.pb({});
                g_y.pb({});
            }
            if (char2int[b-'A'] == -1) {
                char2int[b-'A'] = ind;
                int2char.pb(b);
                ind++;
                g_m.pb({});
                g_y.pb({});
            }
            if (a == b) continue;
            if (m == 'Y') {
                g_y[char2int[a-'A']].pb({c,char2int[b-'A']});
                if (w == 'B') g_y[char2int[b-'A']].pb({c,char2int[a-'A']});
            } else {
                g_m[char2int[a-'A']].pb({c,char2int[b-'A']});
                if (w == 'B') g_m[char2int[b-'A']].pb({c,char2int[a-'A']});
            }
        }
        char ss,ts;
        cin >> ss >> ts;
        if (char2int[ss-'A'] == -1) {
            char2int[ss-'A'] = ind;
            ind++;
            int2char.pb(ss);
            g_m.pb({});
            g_y.pb({});
        }
         if (char2int[ts-'A'] == -1) {
            char2int[ts-'A'] = ind;
            ind++;
            int2char.pb(ts);
            g_m.pb({});
            g_y.pb({});
        }
        
        int s = char2int[ss-'A'];
        int t = char2int[ts-'A'];
        
        
        int ng = g_y.size();

        v<v<ll>> mat_y(ng, v<ll>(ng, INT32_MAX));
        v<v<ll>> mat_m(ng, v<ll>(ng, INT32_MAX));
        forn(i,0,ng) {
            forn(j,0,g_y[i].size()) {
                pair<ll,int> p = g_y[i][j];
                mat_y[i][p.second] = p.first;
            }
        }
        forn(i,0,ng) {
            forn(j,0,g_m[i].size()) {
                pair<ll,int> p = g_m[i][j];
                mat_m[i][p.second] = p.first;
            }
        }
        forn(i,0,ng) {
            mat_m[i][i] = 0;
            mat_y[i][i] = 0;
        }
        forn(k,0,ng) {
            forn(i,0,ng) {
                forn(j,0,ng) {
                    mineq(mat_y[i][j], mat_y[i][k]+mat_y[k][j]);
                    mineq(mat_m[i][j], mat_m[i][k]+mat_m[k][j]);
                }
            }
        }
        ll ans = INT32_MAX;
        v<char> minind;
        forn(i,0,ng) {
                ll pos_ans = mat_y[s][i]+mat_m[t][i];
                if (pos_ans < ans) {
                    minind = {int2char[i]};
                    ans  = pos_ans;
                } else if (ans == pos_ans) minind.pb(int2char[i]);
        }
        sortv(minind);
        if (ans == INT32_MAX) cout << "You will never meet.\n";
        else {
            cout << ans;
            forn(i,0,minind.size()) cout << " " << minind[i];
            cout << "\n";
        }
        
        cin >> n;
    }
}
