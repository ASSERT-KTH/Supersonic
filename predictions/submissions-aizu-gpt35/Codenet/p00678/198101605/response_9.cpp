#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

double EPS = 1e-6;

inline double add(double a, double b) {
  if (fabs(a + b) < EPS * (fabs(a) + fabs(b)))
    return 0;
  return a + b;
}

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(const point& p) const { return point(add(x, p.x), add(y, p.y)); }
  point operator-(const point& p) const { return point(add(x, -p.x), add(y, -p.y)); }
  point operator*(const double d) const { return point(x * d, y * d); }
  point operator/(const double d) const { return point(x / d, y / d); }
};

inline double dist(const point& a, const point& b) {
  const double dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (scanf("%d", &n), n) {
    P.resize(n);
    V.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &x, &y, &v);
      P[i] = point(x, y);
      V[i] = v;
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        const double cur_dist = dist(now, P[j]);
        const double cur_time = cur_dist / V[j];
        if (cur_time > mxd) {
          mx = j;
          mxd = cur_time;
        }
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}