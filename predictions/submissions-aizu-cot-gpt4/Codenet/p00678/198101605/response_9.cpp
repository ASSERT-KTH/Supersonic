#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(double d) { return point(x * d, y * d); }
  point operator/(double d) { return point(x / d, y / d); }
};
double dist_sqr(point a, point b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}
int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
    P.clear();
    V.clear();
    P.reserve(n);
    V.reserve(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < P.size(); j++) {
        double current_dist_sqr = dist_sqr(now, P[j]);
        if (current_dist_sqr / (V[j] * V[j]) > mxd)
          mx = j, mxd = current_dist_sqr / (V[j] * V[j]);
      }
      now = now + ((P[mx] - now) / sqrt(mxd) * d);
    }
    double ans = 0;
    for (int i = 0; i < P.size(); i++) {
      ans = max(ans, sqrt(dist_sqr(now, P[i])) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}