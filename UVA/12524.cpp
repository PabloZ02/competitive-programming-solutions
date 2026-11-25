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


ll lmax = LLONG_MAX/4;
v<v<ll>> dists;
v<v<ll>> M;


pair<int,ll> get_i(int l_i, int r_i, int k, int j) {
    //cout << "Get_i: " << l_i << r_i << k << j << endl;
    pair<int,ll> res = {l_i,dists[l_i+1][j] + M[l_i][k-1]};
    forn(i,l_i+1,r_i) {
        if (dists[i+1][j] + M[i][k-1] < res.second) {
            res = {i, dists[i+1][j] + M[i][k-1]};
        }
    }
    return res;
}

void dcf(int k, int l, int r, int l_i, int r_i) {
    //cout << k << " "<< l << " " << r << " " << l_i << " " << r_i << endl;
    if (l == r || l == n-1) return;
    int mid = (l+1 + r)/2;
    //cout << mid << endl;
    
    pair<int,ll> p = get_i(l_i,min(mid,r_i+1),k,mid);
    //cout << mid << " " << p.second << endl;
    M[mid][k] = p.second;

    dcf(k,l,mid-1,l_i,p.first);
    dcf(k,mid,r,p.first,r_i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    //ofstream mfile;
    //mfile.open("out.txt");
    while(cin >> n) {
        cin >> k;
        ll x,w;
        v<pair<ll,ll>> heaps(n);
        forn(i,0,n) {
            cin >> x >> w;
            heaps[i] = {x,w};
        }
        dists = v<v<ll>>(n, v<ll>(n,0));
        forn(i,1,n) {
            forr(j,i-1,0) dists[j][i] = dists[j+1][i] + (heaps[i].first-heaps[j].first)*heaps[j].second;
        }
        M = v<v<ll>>(n+1, v<ll>(k+1,lmax));
        M[0][0] = 0;
        forn(i,0,n) M[i][1] = dists[0][i];
        forn(i,2,k+1) dcf(i,0,n-1,0,n-1);
        cout << M[n-1][k] << "\n";
    }
    //mfile.close();
}
