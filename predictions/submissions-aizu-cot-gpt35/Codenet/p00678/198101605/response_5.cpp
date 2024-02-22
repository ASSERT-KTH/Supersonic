#include <cstdio>
#include <iostream>
using namespace std;

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
  return dx * dx + dy * dy;
}

int main(void) {
  int n, x, y, v;
  while (cin >> n, n) {
    double r = 0.98;
    point now(0, 0);
    double d = 10;
    while (d > 1e-6) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        cin >> x >> y >> v;
        double curDist = dist(now, point(x, y));
        double time = curDist / v;
        if (time > mxd) {
          mx = j;
          mxd = time;
        }
      }
      now = now + ((point(x, y) - now) / sqrt(dist(point(x, y), now)) * d);
      d *= r;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      double curDist = dist(now, point(x, y));
      double time = curDist / v;
      ans = max(ans, time);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}