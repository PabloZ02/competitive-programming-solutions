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
vi di = {1,-1,0,0};
vi dj = {0,0,1,-1};
int w,h,n;

void flood_fill(int i, int j, int clust_i, int clust_j, v<vi>& grid, v<pii>& cluster) {
    if (i < 0 || i >= w || j < 0 || j >= h || grid[i][j] != 1) return;
    cluster.pb({i,j});
    grid[i][j] = 3;
    forn(k,0,4) {
        flood_fill(i+di[k],j+dj[k],clust_i+di[k],clust_j+dj[k],grid,cluster);
    }
}

void flood_search(int i, int j, v<vi>& grid, v<v<pii>>& clusters) {
    if (i < 0 || i >= w || j < 0 || j >= h || grid[i][j] == 2) return;
    else if (grid[i][j] == 1) {
        v<pii> cluster;
        flood_fill(i,j,0,0,grid,cluster);
        clusters.pb(cluster);
        flood_search(i,j,grid,clusters);
    } else {
        grid[i][j] = 2;
        forn(k,0,4) {
            flood_search(i+di[k],j+dj[k],grid,clusters);
        }
    }

}

void transpose(v<v<pii>>& clusters) {
    forn(i,0,clusters.size()) {
        int mini = clusters[i][0].first;
        int minj = clusters[i][0].second;
        forn(j,1,clusters[i].size()) {
            mineq(mini, clusters[i][j].first);
            mineq(minj, clusters[i][j].second);
        }
        forn(j,0,clusters[i].size()) {
            clusters[i][j].first -= mini;
            clusters[i][j].second -= minj;
        }
    }
}

void rotate(v<pii>& cluster) {
    sortv(cluster);
    v<v<pii>> newc(4, v<pii>(cluster.size()));
    newc[0] = cluster;
    forn(r,1,4) {
        int maxi = newc[r-1][0].first;
        forn(i,0,cluster.size()) {
            maxeq(maxi,newc[r-1][i].first);
        }
        forn(i,0,cluster.size()) {
            newc[r][i] = {newc[r-1][i].second, maxi-newc[r-1][i].first};
        }
        sortv(newc[r]);
    }
    forn(r,1,4) if (newc[r] < cluster) swap(newc[r],cluster);
    
}

void mirror(v<pii>& cluster) {
    int maxj = cluster[0].second;
    v<pii> mirrorc(cluster.size());
    forn(i,0,cluster.size()) maxeq(maxj,cluster[i].second);
    forn(i,0,cluster.size()) mirrorc[i] = {cluster[i].first, maxj-cluster[i].second};
    rotate(mirrorc);
    if (mirrorc < cluster) swap(mirrorc,cluster);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> w >> h >> n;
        v<vi> grid1(w, vi(h,0));
        v<vi> grid2(w, vi(h,0));
        forn(i,0,n) {
            int x,y;
            cin >> x >> y;
            grid1[x][y] = 1;
        }
        forn(i,0,n) {
            int x,y;
            cin >> x >> y;
            grid2[x][y] = 1;
        }
        v<v<pii>> clusters1;
        v<v<pii>> clusters2;
        flood_search(0,0,grid1,clusters1);
        flood_search(0,0,grid2,clusters2);
        transpose(clusters1);
        transpose(clusters2);
        
        
        forn(i,0,clusters1.size()) {
            rotate(clusters1[i]);
            mirror(clusters1[i]);
        }
        forn(i,0,clusters2.size()) {
            rotate(clusters2[i]);
            mirror(clusters2[i]);
        }
        sortv(clusters1);
        sortv(clusters2);
        printb(clusters1 == clusters2);

        /*forn(i,0,clusters1.size()) {
            forn(j,0,clusters1[i].size()) {
                cout << clusters1[i][j].first << " " << clusters1[i][j].second << "\n";
            }
            cout << "c\n";
        }
        cout << "fin\n";
        forn(i,0,clusters2.size()) {
            forn(j,0,clusters2[i].size()) {
                cout << clusters2[i][j].first << " " << clusters2[i][j].second << "\n";
            }
            cout << "c\n";
        }
        cout << "fin\n";*/
    }
}
