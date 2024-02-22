#include <algorithm>
#include <cmath>
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
double dist(point a, point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
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
    int mx = 0;
    double mxd = 0;
    for (int j = 0; j < P.size(); j++) {
      double ratio = dist(now, P[j]) / V[j];
      if (ratio > mxd) {
        mx = j;
        mxd = ratio;
      }
    }
    double max_dist = dist(now, P[mx]);
    for (double d = 10; d > EPS; d *= r) {
      now = now + ((P[mx] - now) / max_dist * d);
    }
    double ans = 0;
    for (const auto& p : P) {
      ans = max(ans, dist(now, p) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}