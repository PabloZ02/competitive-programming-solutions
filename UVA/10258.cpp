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
bool sndcomp(tuple<int,int,int>a, tuple<int,int,int> b) {
    return get<1>(a) > get<1>(b);
}
bool thirdcomp(tuple<int,int,int>a, tuple<int,int,int> b) {
    return get<2>(a) < get<2>(b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TT;
    cin >> TT;
    string ignore; getline(cin,ignore);
    getline(cin,ignore);
    bool passed = false;
    while (TT--) {
        if (passed) cout << "\n";
        else passed = true;
        string line; 
        getline(cin,line);
        vector<vector<pair<bool,int>>>team_problems(101);
        while(line != "") {
            int ind = 0;
            string nums;
            while(line[ind] != ' ') {
                nums.pb(line[ind]);
                ind++;
            } ind++;
            int gnum = stoi(nums);
            string ps;
            while(line[ind] != ' ') {
                ps.pb(line[ind]);
                ind++;
            } ind++;
            int pnum = stoi(ps);
            string ts;
            while(line[ind] != ' ') {
                ts.pb(line[ind]);
                ind++;
            } ind++;
            int tnum = stoi(ts);
            bool solved;
            line[ind] == 'C' ? solved = true : solved = false;
            
            if (team_problems[gnum].empty()) {
                team_problems[gnum] = vector<pair<bool,int>>(10, make_pair(false,0));
            }
            if (!team_problems[gnum][pnum].first) {
                if (line[ind] == 'C')
                team_problems[gnum][pnum] = make_pair(true,team_problems[gnum][pnum].second+tnum);
                else if (line[ind] == 'I')
                team_problems[gnum][pnum] = make_pair(false,team_problems[gnum][pnum].second+20);
            }

            getline(cin,line);
        }
        vector<tuple<int,int,int>> team_rankings;
        forn(i,1,101) {
            if (!team_problems[i].empty()) {
                int problems_solved = 0;
                int time = 0;
                forn(j,1,10) {
                    if(team_problems[i][j].first) {
                        problems_solved++;
                        time += team_problems[i][j].second;
                    }
                }
                team_rankings.pb({i,problems_solved,time});
            } 
        }
        sort(its(team_rankings), thirdcomp);
        sort(its(team_rankings),sndcomp);
        forn(i,0,team_rankings.size()) {
            cout << get<0>(team_rankings[i]) << " " << get<1>(team_rankings[i]) << " " << get<2>(team_rankings[i])
            << "\n";
        }

    }
}
