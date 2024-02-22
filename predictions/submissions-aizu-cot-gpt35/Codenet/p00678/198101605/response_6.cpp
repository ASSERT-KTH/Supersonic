#include <cmath>
#include <iostream>
#include <vector>

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
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void) {
  int n, x, y, v;
  std::vector<point> P;
  std::vector<double> V;
  while (std::cin >> n, n) {
    P.clear();
    V.clear();
    for (int i = 0; i < n; i++) {
      std::cin >> x >> y >> v;
      P.emplace_back(x, y);
      V.emplace_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      auto max_dist_point = std::max_element(P.begin(), P.end(),
                                             [&](const point& p1, const point& p2) {
                                               return dist(now, p1) / V[&p1 - &P[0]] <
                                                      dist(now, p2) / V[&p2 - &P[0]];
                                             });
      now += (*max_dist_point - now) / dist(*max_dist_point, now) * d;
    }
    double ans = 0;
    for (const auto& p : P) {
      ans = std::max(ans, dist(now, p) / V[&p - &P[0]]);
    }
    std::cout.precision(8);
    std::cout << std::fixed << ans << std::endl;
  }
  return 0;
}