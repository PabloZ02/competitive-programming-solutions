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

    int TT;
    cin >> TT;
    while (TT--) {
        string n; cin >> n;
        int k; cin >> k;
        v<bool> nums(13,true);
        v<bool> is_div(13);
        forn(i,0,k) {
            int ind; cin >> ind;
            nums[ind] = false;
        }
        bool wond = true;
        wond = nums[2] || ((n[n.size()-1]-'0') % 2 == 0);
        is_div[2] =  ((n[n.size()-1]-'0') % 2 == 0);
        int evpos = 0, odpos = 0;
        forr(i,n.size()-1,0) {
            evpos += n[i]-'0';
            i--;
            if (i >= 0) odpos += n[i]-'0';
        }
        wond &= nums[3] || ((evpos+odpos) % 3 == 0);
        is_div[3] = ((evpos+odpos) % 3 == 0);
        int last2;
        if (n.size() == 1) last2 = n[0]-'0';
        else {
            string last2s;
            last2s.pb(n[n.size()-2]);
            last2s.pb(n[n.size()-1]);
            last2 = stoi(last2s);
        }
        wond &= nums[4] || (last2 % 4 == 0);
        is_div[4] = (last2 % 4 == 0);
        wond &= nums[5] || ((n[n.size()-1]-'0') % 5 == 0);
        is_div[5] = ((n[n.size()-1]-'0') % 5 == 0);
        wond &= nums[6] || (is_div[2] && is_div[3]);
        string ncpy = n;
        while(ncpy.size() > 8) {
            int sub = (ncpy[ncpy.size()-1]-'0') * 2;
            ncpy.pop_back();
            int carry = sub > 9;
            if (ncpy[ncpy.size()-1]-'0' < (sub%10)) {
                carry ++;
                ncpy[ncpy.size()-1] = ncpy[ncpy.size()-1] + 10 - (sub%10);
            } else {
                ncpy[ncpy.size()-1] -= (sub%10);
            }
            int ind = ncpy.size()-2;
            while(carry > 0) {
                if (ncpy[ind]-'0' < carry) {
                    ncpy[ind] = 10 + (ncpy[ind] == '1') - carry + '0';
                    ind--;
                    carry = 1;
                } else {
                    ncpy[ind] -= carry;
                    carry = 0;
                    
                }
            }
        }
        wond &= nums[7] || (stoi(ncpy) % 7 == 0);
        int last3;
        if (n.size() < 3) last3 = last2;
        else {
            string last3s;
            last3s.pb(n[n.size()-3]);
            last3s.pb(n[n.size()-2]);
            last3s.pb(n[n.size()-1]);
            last3 = stoi(last3s);
        }
        wond &= nums[8] || (last3 % 8 == 0);
        wond &= nums[9] || (((evpos+odpos) % 9) == 0);
        wond &= nums[10] || (is_div[2] && is_div[5]);
        wond &= nums[11] || (abs(evpos-odpos) % 11 == 0);
        wond &= nums[12] || (is_div[3] && is_div[4]);
        cout << n << " - ";
        if (wond) cout << "Wonderful.\n";
        else cout << "Simple.\n";
    }
}
