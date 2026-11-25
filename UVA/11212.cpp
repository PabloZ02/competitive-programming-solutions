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
#define sortv(vec) sort(vec.begin(), vec.end())
#define sortvc(vec, comp) sort(vec.begin(), vec.end(), comp)
#define its(vec) vec.begin(), vec.end()
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

map<ll,int> queue1;
map<ll,int> queue2;
int n;
ll to_num(vi& v) {
    ll ans = 0;
    forn(i,0,n) ans = ans*10 + v[i];
    return ans;
}
void to_vec(ll l, vi& v) {
    
    while(l > 0) {
        v.pb(l % 10);
        l /= 10;
    }
    reverse(its(v));
}
ll sorted;
void displace(int s, int e, int dp, vi& v,vi& vswap) {
    int size = e-s+1;
    if (s > dp) {
        forn(i,0,dp) {
            vswap[i] = v[i];
        }
        forn(i,0,size) {
            vswap[dp+i] = v[s+i]; 
        }
        forn(i,size+dp,v.size()) vswap[i] = v[i-size];
        forn(i,e+1,v.size()) vswap[i] = v[i];
    } else {
        dp -= size;
        forn(i,0,s) vswap[i] = v[i];
        forn(i,0,dp-s) vswap[s+i] = v[e+1+i];
        forn(i,0,size) vswap[i+dp] = v[s+i];
        forn(i,dp+size,v.size()) vswap[i] = v[i];
    }
}

int solve(vi &v) {
    while(1) {
        
        map<ll,int> queue;
        for(auto [vecnum,val] : queue1) {
            vi v;
            to_vec(vecnum,v);
            forn(start,0,n) {
                int end = start;
                //while(end < n-1 && v[end]+1 == v[end+1]) end++;
                //while(end < n && (start == end || v[end] > v[end-1])) {
                while(end < n) {
                    forn(k,0,n+1) {
                        if (k < start || k > end+1 ) {
                            vi vc = v;
                            displace(start,end,k,v,vc);
                            ll vcnum = to_num(vc);
                            //cout << vcnum << endl;
                            if (queue2.count(vcnum) > 0) return val+queue2[vcnum]+1;
                            queue[vcnum] = val+1;
                        }
                    }
                    end++;
                }
            }

        }
        swap(queue1,queue);
        swap(queue1,queue2);
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt = 1;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        vi v(n);
        forn(i,0,n) cin >> v[i];
        sorted = 0;
        forn(i,1,n+1) sorted = sorted*10 + i;
        queue1.clear();
        queue2.clear();
        queue2[sorted] = 0;
        queue1[to_num(v)] = 0;
        if (sorted == to_num(v)) cout << "Case " << tt++ << ": " << "0" << "\n";
        else cout << "Case " << tt++ << ": " << solve(v) << "\n";
    }
}
