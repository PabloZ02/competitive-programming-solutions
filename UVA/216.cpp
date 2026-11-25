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
int full;
int n;
double tsp(int i, int mask, vector<vector<double>>& M, vector<vector<double>>& dist) {
    if (mask == full) return 0.0;
    else if (M[mask][i] != -1.0) return M[mask][i];
    else {
        double ans = DBL_MAX;
        forn(next,0,n) {
            if (!(mask & (1 << next))) mineq(ans,tsp(next, mask | (1 << next),M,dist) + dist[i][next]);
        }
        M[mask][i] = ans;
        return ans;
    }
}

void print_sol(int i,int mask, v<pii>g,double cur_dis, vector<vector<double>>& M, vector<vector<double>>& dist) {
    if (mask == full) return;
    
    forn(next,0,n) {
        
        int nmask = mask | (1 << next);
        if ((!(mask & (1 << next)) && (fabs(cur_dis-dist[i][next]-M[nmask][next]) < FLT_EPSILON)) || nmask == full) {
            cout << "Cable requirement to connect ("<< g[i].first << "," << g[i].second <<  
            ") to ("<<  g[next].first << "," << g[next].second << ") is "<< setprecision(2) << fixed <<
            dist[i][next]+16.0 <<" feet.\n";
            print_sol(next,nmask,g,M[nmask][next], M,dist);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int casen = 1;
    cin >> n;
    while(n != 0) {
        cout << "**********************************************************\n";
        cout << "Network #" << casen << "\n";
        casen++;
        v<pii> g(n);
        forn(i,0,n) {
            int x,y;
            cin >> x >> y;
            g[i] = {x,y};
        }
        int mask = 0;
        full = (1 << n) - 1;
        vector<vector<double>> M(full+2,vector<double>(n,-1.0));
        vector<vector<double>> dist(n, vector<double>(n));
        forn(i,0,n) {
            forn(j,0,n) {
                pii a = g[i];
                pii b = g[j];
                dist[i][j] = sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
                dist[j][i] = dist[i][j];
            }
        }
        int minind;
        double minval = DBL_MAX;
        forn(next,0,n) {
            double t = tsp(next,1 << next,M,dist);
            if (t < minval) {
                minval = t;
                minind = next;
            }
        }
        print_sol(minind,1 << minind,g,minval,M,dist);
        cout << "Number of feet of cable required is " << setprecision(2) << fixed 
        << minval + (n-1)*16.0 << ".\n";
        cin >> n;
    }
}
