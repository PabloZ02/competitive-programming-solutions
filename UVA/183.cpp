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
int ind;
void dtob(string btmap, string &res, int ni, int nj, int mi, int mj) {
    if (ni == nj || mi == mj) return;
    char type = btmap[ind];
    ind++;
    if (type != 'D') {
        forn(i,ni,nj) {
            forn(j,mi,mj) {
                res[i*m+j] = type;
            }
        }
    }
    else {
        int nmid = (nj+ni)/2 + ((nj+ni)%2 == 1);
        int mmid = (mj+mi)/2 + ((mj+mi)%2 == 1);
        dtob(btmap,res,ni,nmid,mi,mmid);
        dtob(btmap,res,ni,nmid,mmid,mj);
        dtob(btmap,res,nmid,nj,mi,mmid);
        dtob(btmap,res,nmid,nj,mmid,mj);
    }
}

string btod(string btmap, int ni, int nj, int mi, int mj) {
    int bsize = (nj-ni)*(mj-mi);
    if (bsize <= 0) return "";
    int count = 0;
    forn(i,ni,nj) {
        forn(j,mi,mj) {
            count += btmap[i*m + j] - '0';
        }
    }
    if (count == bsize) return "1";
    else if (count == 0) return "0";
    string res = "D";
    int nmid = (nj+ni)/2 + ((nj+ni)%2 == 1);
    int mmid = (mj+mi)/2 + ((mj+mi)%2 == 1);
    res += btod(btmap,ni,nmid,mi,mmid);
    res += btod(btmap,ni,nmid,mmid,mj);
    res += btod(btmap,nmid,nj,mi,mmid);
    res += btod(btmap,nmid,nj,mmid,mj);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char kind;
    cin >> kind;
    string btline;
    while(kind != '#') {
        cin >> n >> m;
        string btmap; 
        cin >> btline;
        while(btline.size() != 1 || (btline[0] == '1' || btline[0] == '0')) {
            btmap += btline;
            cin >> btline;
        }

        int bsize = n*m;
        if (kind == 'B') {
            cout << "D " << right << setw(3) << n << " " << right << setw(3) << m << "\n";
            string res = btod(btmap,0,n,0,m);
            int i = 0;
            for(; i < res.size();i++) {
                cout << res[i];
                if (i % 50 == 49) cout << "\n";
            }
            if (i % 50 != 0) cout << "\n";
        }
        else {
            cout << "B " << right << setw(3) << n << " " << right << setw(3) << m << "\n";
            string res(n*m,'0');
            ind = 0;
            dtob(btmap,res,0,n,0,m);
            int i = 0;
            for(; i < res.size();i++) {
                cout << res[i];
                if (i % 50 == 49) cout << "\n";
            }
            if (i % 50 != 0) cout << "\n";
        }
        kind = btline[0];
    }
}
