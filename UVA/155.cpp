#include <bits/stdc++.h>

using namespace std;
typedef complex<int> pt;
#define x real()
#define y imag()
int main() {
    pt center = {1024,1024};
    int k,px,py;
    while(cin >> k >> px >> py, k!= 0 || px != 0 || py != 0) {
        vector<vector<vector<pt>>> squares;
        vector<vector<pt>> v = {{{center.x-k,center.y-k},{center.x+k,center.y-k}, 
            {center.x-k,center.y+k}, {center.x+k,center.y+k}}};
        squares.push_back(v);
        k /= 2;
        int ind = 0;

        while(k > 0) {
            vector<vector<pt>> vp;
            for(int i = 0; i < squares[ind].size(); i++)
            for(int j = 0; j < 4; j++) {
                pt p = squares[ind][i][j];
                vp.push_back({{{p.x-k,p.y-k},{p.x+k,p.y-k},{p.x-k,p.y+k},{p.x+k,p.y+k}}});
            }
            k /= 2;
            ind++;
            squares.push_back(vp);
        }
        pt p = {px,py}; int count = 0;
        for(int i = 0; i < squares.size(); i++)
        for(int j = 0; j < squares[i].size(); j++) {
            count += (px >= squares[i][j][0].x && px <= squares[i][j][1].x 
                && py >= squares[i][j][0].y && py <= squares[i][j][2].y);
        }
        cout << right << setw(3) << count << "\n";
    }
}