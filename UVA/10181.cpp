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
pii num2pos(int n) {return {(n-1)/4, (n-1)%4};}
int pos2num(pii p) {return p.first * 4 + p.second + 1;}
int dist(pii p1, pii p2) {return abs(p1.first-p2.first) + abs(p1.second-p2.second);}
int dist2(int n, pii p) {return dist(num2pos(n),p);}
bool valid(pii p) {return p.first >= 0 && p.first < 4 && p.second >= 0 && p.second < 4;}
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
string dc = "DRUL";
pii zeroPos;
string ans;
int lastMove;

bool idas(v<vi>& square, int rem,int zerodist, int steps, int bound, pii pos) {
    if (rem <= 0) return true;
    else if (steps + max(rem,zerodist) > bound) return false;
    forn(k,0,4) {
        if (k == lastMove) continue;
        pii nextpos = {pos.first+di[k],pos.second+dj[k]};
        int distval = 0;
        int zdval = 0;
        if (valid(nextpos)) {
            if (nextpos.first > pos.first || nextpos.second > pos.second) zdval--;
            else zdval++;
            int curtile = square[nextpos.first][nextpos.second];
            if (dist2(curtile,pos) < dist2(curtile,nextpos)) distval--;
            else distval++;

            swap(square[nextpos.first][nextpos.second], square[pos.first][pos.second]);
            ans.pb(dc[k]);
            int prevMove = lastMove;
            lastMove = (k + 2) % 4;
            if (idas(square,rem+distval,zerodist+zdval,steps+1,bound,nextpos)) return true;
            ans.pop_back();
            lastMove = prevMove;
            swap(square[nextpos.first][nextpos.second], square[pos.first][pos.second]);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    while (TT--) {
        ans = "";
        v<vi> square(4, vi(4));
        int minbound = 0;
        int x;
        forn(i,0,4) {
            forn(j,0,4) {
                cin >> x;
                if (x != 0) minbound += dist(num2pos(x), {i,j});
                else {
                    zeroPos = {i,j};
                    x = 16;
                }
                square[i][j] = x;
            }
        }
        int zerodist = dist(zeroPos, {3,3});
        
        int permutations = 0;
        forn(i,1,17) {
            pii p1 = num2pos(i);
            forn(j,1,i) {
                pii p2 = num2pos(j);
                permutations += square[p1.first][p1.second] < square[p2.first][p2.second]; 
            }
        }
        if ((permutations + zerodist) % 2 != 0) {
            cout << "This puzzle is not solvable.\n";
            continue;
        }
        int rem = minbound;
        maxeq(minbound,zerodist);
        bool solved = false;
        while(minbound <= 45 && !solved) {
            lastMove = -1;
            if (idas(square,rem,zerodist,0,minbound,zeroPos)) {
                solved = true;
                cout << ans << "\n";
            } else {
                minbound += 2;
            }
        }
        if (!solved) cout << "This puzzle is not solvable.\n";
    }
}
