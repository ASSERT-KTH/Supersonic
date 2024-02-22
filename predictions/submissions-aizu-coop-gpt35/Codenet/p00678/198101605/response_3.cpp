#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;
double add(double a, double b) {
  if (a + b < -EPS * (abs(a) + abs(b)) || a + b > EPS * (abs(a) + abs(b)))
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
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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
    for (double d = 10; d > EPS; d *= r*r) {
      int mx = 0;
      double mxd = 0;
      double dist_now_p;
      double v;
      point p_diff;
      for (const auto& p : P) {
        dist_now_p = dist(now, p);
        v = V[mx];
        if (dist_now_p / v > mxd) {
          mx = j;
          mxd = dist_now_p / v;
          p_diff = p - now;
        }
      }
      now = now + ((p_diff) / dist_now_p * d);
    }
    double ans = 0;
    double dist_now_p;
    double v;
    for (const auto& p : P) {
      dist_now_p = dist(now, p);
      v = V[mx];
      ans = max(ans, dist_now_p / v);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}