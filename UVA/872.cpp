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
map<char,int> letter_i;
string letters;
v<v<bool>> successors;
int n;
v<bool> marked;
string intXletters(21,'a');
vi ans(21);
int orders;
v<int> all_succ(int i) {
    vi ans = {};
    marked[i] = true;
    forn(k,0,n) {
        if (!marked[k] && successors[i][k]) {
            ans.insert(ans.end(),its(all_succ(k)));
        }
    }
    forn(k,0,ans.size()) {
        successors[i][ans[k]] = true;
    }
    return ans;
}
void solve(int size) {
    if (size == n) {
        cout << intXletters[ans[0]];
        forn(i,1,size) cout << " " << intXletters[ans[i]];
        cout << "\n";
        orders++;
    }
    forn(k,0,n) {
        if (!marked[k]) {
            bool notsuc = true;
            forn(psuc,0,size) {
                notsuc &= !successors[k][ans[psuc]];
            }
            if (notsuc) {
                marked[k] = true;
                ans[size] = k;
                solve(size+1);
                marked[k] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    cin.ignore();cin.ignore();
    string line;
    bool passed = false;
    while(getline(cin,line)) {
        if (passed) cout << "\n";
        else passed = true;
        int ind = 0;
        orders = 0;
        letters = {};
        sortv(line);
        forn(i,0,line.size()) {
            if (line[i] == ' ') continue;
            char c; c = line[i];
            letters.pb(c);
            letter_i[c] = ind;
            intXletters[ind] = c;
            ind++;
        }
        getline(cin,line);
        n = letters.size();
        successors = v<vector<bool>>(n,v<bool>(n,false));
        fors(i,0,line.size(),4){
            int c1 = letter_i[line[i]];
            int c2 = letter_i[line[i+2]];
            successors[c1][c2] = true;
        }
        marked = v<bool>(n,false);
        forn(i,0,n) {
            if (!marked[i]) {
                all_succ(i);
            }
        }
        forn(i,0,n) {
            marked[i] = false;
        }
        solve(0);
        if (orders == 0) cout << "NO\n";

        cin.ignore();
    }
}
