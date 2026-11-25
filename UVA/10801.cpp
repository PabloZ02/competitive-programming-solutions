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
int di[2] = {1,-1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        string ns,ks;
        int ind = 0;
        while(line[ind] != ' ') {
            ns.pb(line[ind]);
            ind++;
        } ind++;
        while(ind < line.size()) {
            ks.pb(line[ind]);
            ind++;
        }
        int n = stoi(ns);
        int k = stoi(ks);
        vi el_times(n);
        forn(i,0,n) cin >> el_times[i];
        cin.ignore();
        v<vi> el_ind(n, vi(100,-1));
        v<vi> elevators(n, vi({}));
        forn(i,0,n) {
            getline(cin,line);
            int ind = 0;
            while(ind < line.size()) {
                string sel;
                while(ind < line.size() && line[ind] != ' '){
                    sel.pb(line[ind]);
                    ind++;
                } ind++;
                int eln = stoi(sel);
                el_ind[i][eln] = elevators[i].size();
                elevators[i].pb(eln);
            }
        }
        priority_queue<pair<ll,pii>, v<pair<ll,pii>>, greater<pair<ll,pii>>> pq;
        v<v<ll>> dist(n, v<ll>(100,INT32_MAX));
        forn(i,0,n) {
            if (el_ind[i][0] == 0) {
                pq.push({0,{i,0}});
                dist[i][0] = 0;
            }
        }
        while(!pq.empty()) {
            pair<ll,pii> nextq = pq.top();
            pq.pop();
            int cur_el = nextq.second.first;
            int cur_floor_ind = nextq.second.second;
            ll d = dist[cur_el][elevators[cur_el][cur_floor_ind]];
            if (nextq.first > d) continue;
            forn(i,0,2) {
                int ind = cur_floor_ind+di[i];
                if (ind >= 0 && ind < elevators[cur_el].size()) {
                    int el = elevators[cur_el][ind];
                    int floors_dif = abs(el - elevators[cur_el][cur_floor_ind]);
                    if (d+el_times[cur_el]*floors_dif < dist[cur_el][el]) {
                        dist[cur_el][el] = d+el_times[cur_el]*floors_dif;
                        pq.push({dist[cur_el][el], {cur_el,ind}});
                    }
                }
            }
            forn(el,0,n) {
                if (el != cur_el) {
                    int el_floor = elevators[cur_el][cur_floor_ind];
                    int indel = el_ind[el][el_floor];
                    if (indel != -1 && d+60 < dist[el][el_floor]) {
                        dist[el][el_floor] = d+60;
                        pq.push({d+60, {el,indel}});
                    }
                }
            }
        }
        ll ans = INT32_MAX;
        forn(i,0,n) mineq(ans,dist[i][k]);
        if (ans == INT32_MAX) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";

    }
}
