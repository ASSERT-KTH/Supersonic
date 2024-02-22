#include <iostream>
#include <vector>

struct point {
  double x, y;
};

double dist(const point& a, const point& b) {
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
      P.emplace_back(point{x, y});
      V.emplace_back(v);
    }
    double r = 0.98;
    point now{0, 0};
    for (double d = 10; d > 1e-6; d *= r) {
      auto it = std::max_element(P.begin(), P.end(), [&](const point& a, const point& b) {
        return dist(now, a) / V[&a - &P[0]] < dist(now, b) / V[&b - &P[0]];
      });
      now.x += (it->x - now.x) / dist(*it, now) * d;
      now.y += (it->y - now.y) / dist(*it, now) * d;
    }
    double ans = 0;
    for (const auto& p : P) {
      ans = std::max(ans, dist(now, p) / V[&p - &P[0]]);
    }
    std::cout.precision(8);
    std::cout << std::fixed << ans << "\n";
  }
  return 0;
}