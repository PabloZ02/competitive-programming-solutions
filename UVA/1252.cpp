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
int n,m;
vi objs; 
v<vi> M;
v<vi> answers;
vi ones;
vi msb;
vi logs;
int compress_mask(int qmask,int ansmask) {
    int ind = 0;
    int mask = 0;
    int l = msb[qmask];
    fori(i,0,l) {
        if (qmask & (1 << i)) {
            if (ansmask & (1 << i)) mask = mask | (1 << ind);
            ind++;
        }
    }
    return mask;
}

int solve(int qmask, int ansmask) {
    int nmask = compress_mask(qmask,ansmask);
    if (answers[qmask][nmask] <= 2) return answers[qmask][nmask] == 2;
    else if (M[qmask].size() == 0 || M[qmask][nmask] == -1) {
        if (M[qmask].size() == 0) M[qmask] = vi(1 << (ones[qmask]+1),-1);
        int ans = m;
        forr(k,m-1,0) {
            int nmask1 = compress_mask(qmask | (1 << k), ansmask | (1 << k));
            int nmask2 = compress_mask(qmask | (1 << k), ansmask);
            if (!(qmask & (1 << k)) && answers[(1 << k) | qmask][nmask1] && answers[(1 << k) | qmask][nmask2]) {
            mineq(ans,1 + max(solve((1 << k) | qmask,ansmask | (1 << k)),
            solve((1 << k) | qmask,ansmask)));
            if (ans == logs[answers[qmask][nmask]]) break;
            }
        }
        
        M[qmask][nmask] = ans;
    }
    return M[qmask][nmask];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> m >> n, n != 0) {
        objs = vi(n);
        logs = vi(n+1);
        string obj;
        forn(i,0,n) {
            cin >> obj;
            int cur = 0;
            forn(k,0,m) if (obj[k] == '1') cur = cur | (1 << k);
            objs[i] = cur;
            logs[i] = ceil(log2((double)i)); 
        }
        answers = v<vi>(1 << m);
        ones = vi(1 << m,0);
        msb = vi(1 << m,0);
        msb[0] = 0;
        forn(i,0,m) {
            forn(j,0,1<<i) { 
                msb[(1 << i) | j] = i;
                ones[(1 << i) | j] = ones[j]+1;
                answers[(1 << i) | j] = vi(1 << (ones[j]+2),0);
            }
            
        }
        answers[0] = {n};
        int mask;
        forn(curind,0,n) {
            int cur = objs[curind];
            forn(i,0,m) {
                forn(j,0,1<<i) {
                    int ind = 0;
                    mask = 0;
                    int nmask = j | (1 << i);
                    fori(k,0,i) if (nmask & (1 << k)) {
                        mask = mask | (((cur & (1 << k)) != 0) << ind);
                        ind++;
                    }
                    answers[(1 << i) | j][mask]++;
                }
            }
        }
        M = v<vi>(1<<m, vi({}));
        
        cout << solve(0,0) << "\n";
        
    }
}
