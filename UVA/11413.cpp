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

bool canfill(int mid, int n, int m, vi& cap) {
    int cont = 0; int curcap = 0;
    forn(i,0,n) {
        if (curcap + cap[i] <= mid) {
            curcap += cap[i];
        } else {
            curcap = 0; cont++; i--;
            if (cont == m) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string nm;
    while(getline(cin,nm)) {
        if (nm == "") break;
        int i = 0;
        string ns;
        while(nm[i] != ' ') {
            ns += nm[i];
            i++;
        }
        i++;
        int n = stoi(ns);
        string ms;
        while(i < nm.size()) {
            ms += nm[i];
            i++;
        }
        int m = stoi(ms);
        vi cap(n);
        int low = 0;
        int high = 0;
        forn(i,0,n) {
            int num; cin >> num;
            cap[i] = num;
            high += num;
            maxeq(low,num);
        }
        while(high-low > 1) {
            int mid = (low+high)/2;
            if (canfill(mid,n,m,cap)) high = mid;
            else low = mid;
        }
        if (canfill(low,n,m,cap)) cout << low << "\n";
        else cout << high << "\n";
        cin.ignore();
    }
}
