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

    int n;
    while(cin >> n) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        bool is_stack = true;
        bool is_q = true;
        bool is_pq = true;
        forn(i,0,n) {
            int c, x;
            cin >> c >> x;
            if (c == 1) {
                st.push(x);
                q.push(x);
                pq.push(x);
            } else {
                if (st.size() > 0) {
                    is_stack &= st.top() == x;
                    st.pop();
                    is_q &= q.front() == x;
                    q.pop();
                    is_pq &= pq.top() == x;
                    pq.pop(); 
                } else {
                    is_stack = false;
                    is_q = false;
                    is_pq = false;
                }
            }
        }
        if (!(is_stack || is_q || is_pq)) cout << "impossible\n";
        else if (is_stack && !(is_q || is_pq)) cout << "stack\n";
        else if (is_q && !(is_stack || is_pq)) cout << "queue\n";
        else if (is_pq && !(is_stack || is_q)) cout << "priority queue\n";
        else cout << "not sure\n";
    }
}
