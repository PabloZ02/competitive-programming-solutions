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

    string word;
    set<string> dict;
    while(1) {
        cin >> word;
        if (word == "#") break;
        dict.insert(word);
    }
    cin.ignore();
    string cypher;
    getline(cin,cypher);
    int max_m = 0;
    string max_s;
    forn(i,0,26) {
        forn(i,0,cypher.size()) {
            if (cypher[i] == 'Z') cypher[i] = ' ';
            else if (cypher[i] == ' ') cypher[i] = 'A';
            else cypher[i]++;
        }
        //char * cy = cypher.data();
        char * cy = &cypher[0];
        char * cc = ( char *)malloc(strlen(cy)+1);
        strcpy(cc,cy);
        int m = 0;
        auto pt = strtok(cc," ");
        while(pt != nullptr) {
            if (dict.count(pt) > 0) m++;
            pt = strtok(NULL, " ");
        }
        if (m > max_m) max_s = cypher;
        free(cc);
    }
    //char * cm = max_s.data();
    char * cm = &max_s[0];
    auto pt = strtok(cm, " ");
    string line;

    while(pt != nullptr) {
        if (line.size() + 1 + strlen(pt) > 60) {
            cout << line << "\n";
            line = (string) (pt);
        }
        else {
            if (!line.empty()) line += " ";
            line += (string) (pt);
        }
        pt = strtok(NULL, " ");
    }
    cout << line << "\n";
}
