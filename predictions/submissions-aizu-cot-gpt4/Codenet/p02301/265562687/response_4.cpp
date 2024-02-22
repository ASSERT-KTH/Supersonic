#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }
  double norm() const { return x * x + y * y; }
  double abs() const { return sqrt(norm()); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

std::istream &operator>>(std::istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

// Rest of the code remains the same...

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> p(n);
  for (int i = 0; i < n; ++i)
    std::cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}