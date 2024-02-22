#include <bits/stdc++.h>
#include <cassert>
#include <cmath>

using ll = long long;
using pii = std::pair<int, int>;
constexpr double EPS = 1e-10;
constexpr int MAX_N = 100;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  P operator*(double k) const { return P(x * k, y * k); }
  P operator/(double k) const { return P(x / k, y / k); }
  bool operator==(const P &p) const {
    return (std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS);
  }
  double norm() const { return x * x + y * y; }
  double abs() const { return std::sqrt(norm()); }
};

struct C {
  P cent;
  double r;
};

struct L {
  P p1, p2;
};

using Polygon = std::vector<P>;
using Vector = P;

inline double dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
inline double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }

// Other unchanged functions...

int main() {
  int N;
  P ps[MAX_N];
  while (std::cin >> N && N) {
    for (int i = 0; i < N; ++i) {
      char ch;
      std::cin >> ps[i].x >> ch >> ps[i].y;
    }
    std::vector<P> res = convex_hull(ps, N);
    std::cout << N - res.size() << std::endl;
  }

  return 0;
}