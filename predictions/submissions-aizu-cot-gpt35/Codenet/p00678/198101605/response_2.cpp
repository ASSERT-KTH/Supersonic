#include <cmath>
#include <cstdio>
#include <iostream>

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(double d) { return point(x * d, y * d); }
};

double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  int n, x, y, v;
  while (std::cin >> n, n) {
    double r = 0.98;
    point now(0, 0);
    double ans = 0;

    for (double d = 10; d > 1e-9; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        std::cin >> x >> y >> v;
        point p(x, y);
        double cur_dist = dist(now, p);
        double cur_mxd = cur_dist / v;
        if (cur_mxd > mxd) {
          mxd = cur_mxd;
          mx = j;
        }
      }
      now = now + ((point(x, y) - now) * d / dist(point(x, y), now));
    }

    for (int i = 0; i < n; i++) {
      std::cin >> x >> y >> v;
      point p(x, y);
      double cur_dist = dist(now, p);
      double cur_ans = cur_dist / v;
      ans = std::max(ans, cur_ans);
    }

    printf("%.8f\n", ans);
  }
  return 0;
}