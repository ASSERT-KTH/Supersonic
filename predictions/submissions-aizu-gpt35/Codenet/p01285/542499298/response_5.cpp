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
    return (p2 == s.p2) ? p1 < s.p1 : (p2 < s.p2);
  }
  bool operator==(const Segment &s) const {
    return (s.p1 == p1 && s.p2 == p2) || (s.p1 == p2 && s.p2 == p1);
  }
};
typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double norm(Point a) { return a.x * a.x + a.y * a.y; }
double abs(Point a) { return sqrt(norm(a)); }
Point rotate(Point a, double rad) {
  return Point(cos(rad) * a.x - sin(rad) * a.y,
               sin(rad) * a.x + cos(rad) * a.y);
}
double toRad(double agl) { return agl * M_PI / 180.0; }
double getArg(Point a, Point b, Point c) {
  double arg1 = atan2(b.y - a.y, b.x - a.x);
  double arg2 = atan2(c.y - b.y, c.x - b.x);
  double arg = fabs(arg1 - arg2);
  while (arg > M_PI)
    arg -= 2.0 * M_PI;
  return fabs(arg);
}
int ccw(Point p0, Point p1, Point p2) {
  Point a = p1 - p0;
  Point b = p2 - p0;
  if (cross(a, b) > EPS)
    return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS)
    return CLOCKWISE;
  if (dot(a, b) < -EPS)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}
bool intersectLL(Line l, Line m) {
  return abs(cross(l.p2 - l.p1, m.p2 - m.p1)) > EPS ||
         abs(cross(l.p2 - l.p1, m.p1 - l.p1)) < EPS;
}
bool intersectLS(Line l, Line s) {
  return cross(l.p2 - l.p1, s.p1 - l.p1) * cross(l.p2 - l.p1, s.p2 - l.p1) <
         -EPS;
}
bool intersectLP(Line l, Point p) {
  return abs(cross(l.p2 - p, l.p1 - p)) < EPS;
}
bool intersectSS(Line s, Line t) {
  return ccw(s.p1, s.p2, t.p1) * ccw(s.p1, s.p2, t.p2) <= 0 &&
         ccw(t.p1, t.p2, s.p1) * ccw(t.p1, t.p2, s.p2) <= 0;
}
bool intersectSP(Line s, Point p) {
  return abs(s.p1 - p) + abs(s.p2 - p) - abs(s.p2 - s.p1) < EPS;
}
Point projection(Line l, Point p) {
  double t = dot(p - l.p1, l.p1 - l.p2) / norm(l.p1 - l.p2);
  return l.p1 + (l.p1 - l.p2) * t;
}
Point reflection(Line l, Point p) { return p + (projection(l, p) - p) * 2; }
double distanceLP(Line l, Point p) { return abs(p - projection(l, p)); }
double distanceLL(Line l, Line m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);
}
double distanceLS(Line l, Line s) {
 