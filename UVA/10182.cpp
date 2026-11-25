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
int di[4] = {-1,0,1,0};
int dj[4] = {0,-1,0,1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string ns;
    while(getline(cin,ns)) {
        int n = stoi(ns);
        double n12 = n*12;
        int i = floor((3.0+sqrt(n12-3.0))/6.0);
        int x = i-1;
        int y = 0;
        int dif = n-3*i*(i-1)-1;
        if (dif != 0) {
            dif--;
            y++;
            if (dif != 0) {
            int len[4] = {i*2-1,i,i*2,i};
            forn(k,0,4) {
                int inc = min(dif,len[k]);
                x += inc*di[k];
                y += inc*dj[k];
                dif -= inc;
                if (dif == 0) {
                    if (k == 0) {
                        if (inc > len[k]/2) y += len[k]/2;
                        else y += inc;
                        
                    } else if (k == 2) {
                        if (inc > len[k]/2) y -= len[k]/2;
                        else y -= inc;
                    }

                    break;
                }
                else if (k == 0) y += len[k]/2;
                else if (k == 2) y-= len[k]/2;
            }
        } 
        }
        cout << x << " " << y << "\n";
    }
}
