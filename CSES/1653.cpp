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
ll x;
v<ll> sums;
vi M;
v<ll> w;
int solve(int bmaskcpy) {
    if (bmaskcpy == 0) return 0;
    if (M[bmaskcpy] == -1) {
        //cout << bmask << "\n";
        int ans = n;
        int fst = 0;
        int ansteps = 1;
        int bmask = bmaskcpy;
        while(!(bmask & (1 << fst))) fst++;
        forr(i,n-1,fst) {
            if ((1 << i & bmask) && w[i] + w[fst] > x) {
                ansteps++;
                bmask = bmask ^ (1 << i);
            } else if ((1 << i) & bmask) break;
        }
        if (sums[bmask] <= x) ans = ansteps - (bmask == 0);
        else {

            for(int nmask = bmask; nmask != 0; nmask = (nmask-1) & bmask) {
            if (sums[nmask] <= x  && !(nmask && !(nmask & (nmask-1)))) {
                if (sums[nmask | (bmask & ~((bmask & ~nmask)-1))] > x) {
                    int padding = bmask & ~(nmask-1) & ~((nmask & ~(nmask-1))); 
                    if (padding == 0 || sums[(nmask &  (nmask-1)) | (padding & ~(padding-1))] > x) {
                        mineq(ans, ansteps + solve(bmask & ~nmask));
                        if (ans == 1) break;
                    }
                }
            }
        }
        }
        M[bmaskcpy] = ans;
    }
    return M[bmaskcpy];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    w = v<ll>(n);
    forn(i,0,n) cin >> w[i];
    sortv(w);
    sums = v<ll>((1 << n) + 1,0);
    forn(i,0,n) {
        forn(j,0, 1 << i) {
            sums[(1 << i) + j] = sums[j] + w[i];
        }
    }
    //forn(i,0,1 << n) cout << sums[i] << "\n";
    M = vi((1 << n) + 1,-1);
    int ans = 0;
    int mask = (1 << n)-1;
    forn(i,0,n) {
        bool not_alone = false;
        forb(j,0,n,!not_alone) not_alone =  (i != j && w[i]+w[j] <= x);
        if (!not_alone) {
            mask = mask ^ (1 << i);
            ans++;
        }
    }
    cout << solve(mask)+ans << "\n";
}
