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
int n;
map<string,int> btoint;
vector<string> inttob;
vector<pair<int,vector<bool>>> gto;
vi ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string ns;
    int casen = 1;
    while(getline(cin,ns)) {
        n = stoi(ns);
        gto = vector<pair<int,vector<bool>>>(n,{0, vector<bool>(n,false)}); 
        ans = {};
        inttob = vector<string>(n);
        forn(i,0,n) {
            string b; cin >> b;
            btoint[b] = i;
            inttob[i] = b;
        }
        int m; cin >> m;
        forn(i,0,m) {
            string b1,b2;
            cin >> b1 >> b2;
            if (!gto[btoint[b2]].second[btoint[b1]]) {
                gto[btoint[b2]].first++;
                gto[btoint[b2]].second[btoint[b1]] = true;
            }
        }
        
        priority_queue<int, vi, greater<int>> q;
        forn(i,0,n) if(gto[i].first == 0) q.push(i);
        while(!q.empty()) {
            int v = q.top();
            ans.pb(v);
            q.pop();
            forn(i,0,n) {
                if (gto[i].second[v]) {
                    gto[i].first--;
                    if (gto[i].first == 0) q.push(i);
                }
            }
        }
        cout << "Case #" << casen << ": ";
        cout << "Dilbert should drink beverages in this order:";
        forn(i,0,n) {
            cout << " " << inttob[ans[i]];
        }
        cout << ".\n\n";
        casen++;
        cin.ignore();cin.ignore();
    }
}
