#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;
class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  Point operator*(Point a) {
    return Point(x * a.x - y * a.y, x * a.y + y * a.x);
  }
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
  Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
  bool operator<(const Segment &s) const {
    return (p2 == s.p2) ?