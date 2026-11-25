#include <bits/stdc++.h>

using namespace std;

pair<int,string> solve(double b, double h) {
    string mode = "grid";
    int ans = floor(b) * floor(h);
    double circleh = sqrt(1-0.5*0.5);
    int verticalc = 0;
    if (h >=1) {
        verticalc++; h--;
    } else return {0,"grid"};
    verticalc += h / circleh;
    if (fmod(b,1.0) >= 0.5) {
        int ans2 = verticalc*floor(b);
        if (ans2 > ans) {
            swap(ans2,ans);
            mode = "skew";
        }
    }
    int ans2 = (verticalc/2)*(2*(int)(b)-1);
    if (verticalc % 2 == 1) ans2 += int(b);
    if (ans2 > ans) {
            swap(ans2,ans);
            mode = "skew";
    }
    return {ans,mode};
}

int main() {
    double b,h;
    while(cin >> b >> h) {
        if (b < 1 || h < 1) {
            cout << "0 grid\n";
            continue;
        }
        pair<int,string> ans = solve(b,h);
        pair<int,string> ans2 = solve(h,b);
        if (ans2.first > ans.first || (ans2.first == ans.first && ans2.second == "grid"))
            swap(ans2, ans);
        cout << ans.first << " " << ans.second << "\n";

    }
}