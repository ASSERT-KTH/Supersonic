#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b)))
        return 0;
    return a + b;
}

struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+(point p) { return point(add(x, p.x), add(y, p.y)); }
    point operator-(point p) { return point(add(x, -p.x), add(y, -p.y)); }
    point operator*(double d) { return point(x * d, y * d); }
    point operator/(double d) { return point(x / d, y / d); }
};

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void) {
    int n, x, y, v;
    vector<point> P;
    vector<double> V;
    
    while (cin >> n, n) {
        P.resize(n);
        V.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> v;
            P[i] = point(x, y);
            V[i] = v;
        }
        
        double r = 0.98;
        point now(0, 0);
        
        for (double d = 10; d > EPS; d *= r) {
            int mx = 0;
            double mxd = 0;
            
            for (int j = 0; j < P.size(); j++) {
                double currDist = dist(now, P[j]) / V[j];
                
                if (currDist > mxd) {
                    mx = j;
                    mxd = currDist;
                }
            }
            
            now = now + ((P[mx] - now) / dist(P[mx], now) * d);
        }
        
        double ans = 0;
        
        for (int i = 0; i < P.size(); i++) {
            ans = max(ans, dist(now, P[i]) / V[i]);
        }
        
        cout.precision(8);
        cout << fixed << ans << endl;
    }
    
    return 0;
}