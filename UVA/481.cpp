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

    string nline;
    vi v;
    while(getline(cin,nline)) {
        if (nline == "") break;
        v.pb(stoi(nline));        
    }
    if (v.size() == 0) {
        cout << "0\n" << "-\n"; return 0;
    }
    int n = v.size();
    vi ans(n);
    vi ans_ind(n);
    vi P(n); 
    int lis = 0, lis_end = 0;
    forn(i,0,n) {
        vi::iterator it = lower_bound(ans.begin(), ans.begin()+lis, v[i]);
        int index = distance(ans.begin(),it);
        ans[index] = v[i];
        ans_ind[index] = i;
        if (index == 0) P[i] = -1;
        else P[i] = ans_ind[index-1];    
        if (index+1 > lis) {
            lis = index+1;
            lis_end = i;
        }
    }
    stack<int> s;
    for(int x = lis_end; x >= 0; x = P[x]) s.push(v[x]);
    cout << lis << "\n";
    cout << "-\n";
    while(!s.empty()) {
        cout << s.top() << "\n"; s.pop();
    }
}
