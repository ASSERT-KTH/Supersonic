#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;
double add(double a, double b) {
  if (a + b < -EPS * (abs(a) + abs(b)))
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
double distSquared(point a, point b) {
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
    P.clear();
    V.clear();
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    double d = 10.0;
    while (d > EPS) {
      int mx = 0;
      double mxdSquared = 0;
      for (int j = 0; j < P.size(); j++) {
        double dSquared = distSquared(now, P[j]);
        if (dSquared > mxdSquared) {
          mx = j;
          mxdSquared = dSquared;
        }
      }
      double distance = sqrt(mxdSquared);
      now = now + ((P[mx] - now) / distance * d);
      d *= r;
    }
    double ans = 0;
    for (int i = 0; i < P.size(); i++) {
      double distance = sqrt(distSquared(now, P[i]));
      ans = max(ans, distance / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}