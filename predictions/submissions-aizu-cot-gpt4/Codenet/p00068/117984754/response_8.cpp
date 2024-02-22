#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

using ll = long long;
using pii = std::pair<int, int>;
constexpr double INF = 999999999;
constexpr double EPS = 1e-10;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(double k) const { return P(x * k, y * k); }
  P operator/(double k) const { return P(x / k, y / k); }
  bool operator==(const P &p) const {
    return (std::fabs(x - p.x) < EPS && std::fabs(y - p.y) < EPS);
  }
  double norm() const { return x * x + y * y; }
  double abs() const { return std::sqrt(norm()); }
};

using Polygon = std::vector<P>;
using Vector = P;
constexpr int MAX_N = 100;
using ps_array = std::array<P, MAX_N>;

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
ps_array ps;

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

std::vector<P> convex_hull(ps_array &ps, int n) {
  std::sort(ps.begin(), ps.begin() + n, cmp_x);
  int k = 0;
  std::vector<P> qs(n * 2);
  for (int i = 0; i < n; i++) {
    while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

int main() {
  int N;
  while (std::cin >> N && N) {
    for(int i = 0; i < N; i++) {
      char ch;
      std::cin >> ps[i].x >> ch >> ps[i].y;
    }
    std::vector<P> res = convex_hull(ps, N);
    std::cout << N - res.size() << std::endl;
  }
}