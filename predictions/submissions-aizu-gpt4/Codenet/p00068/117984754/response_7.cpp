#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0) : x(_x), y(_y){};
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  bool operator==(const Point &p) const {
    return std::fabs(x - p.x) < 1e-10 && std::fabs(y - p.y) < 1e-10;
  }
  double norm() const { return x * x + y * y; }
};

double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

bool cmp_x(const Point &p, const Point &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

std::vector<Point> convex_hull(Point *ps, int n) {
  std::sort(ps, ps + n, cmp_x);
  int k = 0;
  std::vector<Point> qs(n * 2);
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
    Point ps[100];
    for (int i = 0; i < N; i++) {
      char ch;
      std::cin >> ps[i].x >> ch >> ps[i].y;
    }
    std::vector<Point> res = convex_hull(ps, N);
    std::cout << N - res.size() << std::endl;
  }
}