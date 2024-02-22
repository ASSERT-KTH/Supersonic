#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};
typedef std::vector<Point> Polygon;

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double abs(Point a) { return std::sqrt(a.x * a.x + a.y * a.y); }
bool operator<(const Point& p1, const Point& p2) {
  return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
}

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