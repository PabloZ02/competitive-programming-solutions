#include <bits/stdc++.h>

using namespace std;


struct point {
    double x;
    double y;
    double z;
};

double dist(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int main() {
    vector<point> v;
    while(1) {
        double x,y,z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        v.push_back({x,y,z});
    }

    vector<int> counts(10);
    for(int i = 0; i < v.size(); i++) {
        int mindist = 10;
        for(int j = 0; j < v.size(); j++)
        if (j != i)
            mindist = min(mindist, (int)dist(v[i],v[j]));
        if (mindist < 10) counts[mindist]++;
    }
    for(int i = 0; i < 10; i++) cout << setw(4) << right << counts[i];
    cout << "\n";
}