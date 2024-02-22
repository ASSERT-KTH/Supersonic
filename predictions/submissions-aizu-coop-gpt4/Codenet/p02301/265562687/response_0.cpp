#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

const double EPS = 1e-10;
const double PI = 3.141592653589793238;
typedef long long ll;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator/(double k) { return Point(x / k, y / k); }
  inline double norm() { return x * x + y * y; }
  inline double abs() { return sqrt(norm()); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

typedef Point Vector;
typedef std::vector<Point> Polygon;

inline double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
inline double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

Polygon convex_hull(Polygon ps) {
  int n = ps.size();
  std::sort(ps.begin(), ps.end());
  int k = 0;
  Polygon qs(n * 2);
  for (int i = 0; i < n; i++) {
    while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

double diameter(Polygon s) {
  Polygon p = convex_hull(s);
  int n = p.size();
  if (n == 2)
    return (p[0] - p[1]).abs();
  int i = 0, j = 0;
  for (int k = 0; k < n; k++) {
    if (p[i] < p[k])
      i = k;
    if (!(p[j] < p[k]))
      j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while (i != sj || j != si) {
    res = std::max(res, (p[i] - p[j]).abs());
    if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0.0) {
      i = (i + 1) % n;
    } else {
      j = (j + 1) % n;
    }
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; i++)
    std::cin >> p[i].x >> p[i].y;
  printf("%.12f\n", diameter(p));
  return 0;
}