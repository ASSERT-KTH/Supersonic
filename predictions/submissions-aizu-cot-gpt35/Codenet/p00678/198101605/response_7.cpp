#include <iostream>
#include <cmath>
#include <vector>

constexpr double EPS = 1e-6;

struct point {
  double x, y;

  point(double x, double y) : x(x), y(y) {}
};

double dist(const point& a, const point& b) {
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int main() {
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
      int mx = 0;
      double mxd = 0;

      for (const auto& p : P) {
        double dist_p = dist(now, p);
        if (dist_p / V[mx] > mxd) {
          mx = &p - P.data();
          mxd = dist_p / V[mx];
        }
      }

      now = point(now.x + (P[mx].x - now.x) / dist(P[mx], now) * d,
                  now.y + (P[mx].y - now.y) / dist(P[mx], now) * d);
    }

    double ans = 0;

    for (const auto& p : P) {
      ans = std::max(ans, dist(now, p) / V[&p - P.data()]);
    }

    std::cout << std::fixed;
    std::cout.precision(8);
    std::cout << ans << "\n";
  }

  return 0;
}