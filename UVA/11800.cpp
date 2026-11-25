#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef complex<double> pt;
#define x real()
#define y imag()

double cross(pt v, pt w) {return (conj(v)*w).y;}
double dot(pt v, pt w) {
    return (conj(v)*w).x;
}
double orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
bool para(pt v1, pt v2) {return fabs(cross(v1,v2)) < 1e-6;}
bool inter(pt a, pt b, pt c, pt d) {
    double oa = orient(c,d,a);
    double ob = orient(c,d,b);
    double oc = orient(a,b,c);
    double od = orient(a,b,d);
    return (oa*ob < 0 && oc*od < 0);
}
double angle(pt v, pt w){
    return acos(dot(v,w) / abs(v) / abs(w));
}

enum shape {
    SQUARE,RECTANGLE, RHOMBUS, PARALLELOGRAM,TRAPEZIUM,SIMPLE_POLYGON
};

vector<string> shapes = {"Square", "Rectangle", "Rhombus", "Parallelogram",
    "Trapezium", "Ordinary Quadrilateral"};

double eq(double a, double b) {return fabs(a-b) < 1e-6;}

int main() {
    int n; cin >> n;
    for(int tt = 1; tt <= n; tt++) {
        double xp,yp;
        vector<pt> v(4);
        vector<int> indices = {0,1,2,3};
        shape best = SIMPLE_POLYGON;
        for(int i = 0; i < 4; i++) {
            cin >> xp >> yp; v[i] = {xp,yp};
        }
        vector<pt> or_v = {v[0],v[1],v[2],v[3]};
        do {
            for(int i = 0; i < 4; i++) v[i] = or_v[indices[i]];

            if (inter(v[0],v[1],v[2],v[3]) || inter(v[1],v[2],v[3],v[0]) || 
                inter(v[2],v[3],v[0],v[1]) || inter(v[3],v[0],v[1],v[2])) continue;

            vector<double> angles(4), lengths(4);
            for(int i = 0; i < 4; i++) {
                angles[i] = angle(v[i]-v[(i+1)%4],v[(i+2)%4]-v[(i+1)%4]);
                lengths[i] = abs(v[i] - v[(i+1)%4]);
            }
            vector<double> ol = {lengths[0],lengths[1],lengths[2],lengths[3]};
            sort(lengths.begin(), lengths.end());
            sort(angles.begin(),angles.end());
            if (fabs(angles[0] - M_PI/2) < 1e-6 && fabs(angles[3]-M_PI/2) < 1e-6) {
                if (eq(lengths[0],lengths[3])) best = SQUARE;
                else if (eq(lengths[0],lengths[1]) && eq(lengths[2],lengths[3])
                    && best > SQUARE) best = RECTANGLE;
            } else if (eq(lengths[0],lengths[3]) && best > RHOMBUS) best = RHOMBUS;
            else if ((eq(ol[0],ol[2]) && eq(ol[1],ol[3]))
                    && best > PARALLELOGRAM) {
                        best = PARALLELOGRAM;
                    }
            else if ((para(v[1]-v[0], v[2]-v[3]) || para(v[2]-v[1], v[3]-v[0])) 
            && best > TRAPEZIUM)
                best = TRAPEZIUM;

        } while(next_permutation(indices.begin(), indices.end()));
        cout << "Case " << tt << ": " << shapes[best] << "\n";
    }
}