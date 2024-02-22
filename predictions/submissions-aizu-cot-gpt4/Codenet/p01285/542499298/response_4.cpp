#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <cstdio>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double a) const { return Point(a * x, a * y); }
  Point operator/(double a) const { return Point(x / a, y / a); }
  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : (!equals(y, p.y) && y < p.y);
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(const Point& p1 = Point(), const Point& p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
  bool operator<(const Segment &s) const {
    return (p2 == s.p2) ? p1 < s.p1 : p2 < s.p2;
  }
  bool operator==(const Segment &s) const {
    return (s.p1 == p1 && s.p2 == p2) || (s.p1 == p2 && s.p2 == p1);
  }
};

// ... Rest of the code (too long to include here) ...

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<Line> vec(n);
    rep(i, n) std::cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}