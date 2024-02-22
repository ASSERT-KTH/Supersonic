#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const double EPS = 1e-10;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  P operator*(double k) const { return P(x * k, y * k); }
  P operator/(double k) const { return P(x / k, y / k); }
  bool operator==(const P &p) const {
    return (std::fabs(x - p.x) < EPS && std::fabs(y - p.y) < EPS);
  }
  double norm() const { return x * x + y * y; }
  double abs() const { return std::sqrt(norm()); }
};

struct L {
  P p1, p2;
};

double cross(const P &a, const P &b) { return a.x * b.y - a.y * b.x; }
int ccw(const P &p0, const P &p1, const P &p2) {
  P a = p1 - p0;
  P b = p2 - p0;
  double cross_ab = cross(a, b);
  if (cross_ab > EPS)
    return 1;
  if (cross_ab < -EPS)
    return -1;
  if (dot(a, b) < -EPS)
    return 2;
  if (a.norm() < b.norm())
    return -2;
  return 0;
}

bool intersect(const P &p1, const P &p2, const P &p3, const P &p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

double distance_l_p(const L &l, const P &p) {
  return std::fabs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

bool intersect_circle_point(const P &center, double r, const L &line) {
  return distance_l_p(line, center) <= r + EPS;
}

bool isSimple(const std::vector<P> &pol) {
  size_t pol_size = pol.size();
  for (size_t i = 0; i < pol_size; i++) {
    for (size_t j = i + 2; j < pol_size; j++) {
      if (i == j || i == (j - 1 + pol_size) % pol_size ||
          i == (j + 1 + pol_size) % pol_size)
        continue;
      if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
        return false;
    }
  }
  return true;
}

bool isPointInsidePolygon(const std::vector<L> &side, const P &p) {
  int c = 0, sideSum = side.size();
  for (int i = 0; i < sideSum; i++) {
    if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
      c++;
  }
  return !(c % sideSum);
}

bool cmp_x(const P &p, const P &q) {
  return p.x < q.x || (p.x == q.x && p.y < q.y);
}

std::vector<P> convex_hull(P *ps, int n) {
  std::sort(ps, ps + n, cmp_x);
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
  return std::vector<P>(qs.begin(), qs.begin() + k - 1);
}

int main() {
  int N;
  while (std::cin >> N && N) {
    std::vector<P> ps(N);
    for (int i = 0; i < N; i++) {
      char ch;
      std::cin >> ps[i].x >> ch >> ps[i].y;
    }
    std::vector<P> res = convex_hull(&ps[0], N);
    std::cout << N - res.size() << std::endl;
  }
  return 0;
}