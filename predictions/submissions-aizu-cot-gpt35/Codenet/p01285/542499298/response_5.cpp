#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-6;
const string MANY = "Many";
const string NONE = "None";

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Line {
public:
  Point p1, p2;
  int index;
  Line(Point p1 = Point(), Point p2 = Point(), int index = -1)
    : p1(p1), p2(p2), index(index) {}
};

double getArg(Point a, Point b, Point c) {
  double arg1 = atan2(b.y - a.y, b.x - a.x);
  double arg2 = atan2(c.y - b.y, c.x - b.x);
  double arg = arg1 - arg2;
  while (arg > M_PI)
    arg -= 2.0 * M_PI;
  return fabs(arg);
}

bool intersectLL(const Line& l, const Line& m) {
  return fabs((l.p2 - l.p1).x * (m.p2 - m.p1).y - (l.p2 - l.p1).y * (m.p2 - m.p1).x) > EPS ||
         fabs((l.p2 - l.p1).x * (m.p1 - l.p1).y - (l.p2 - l.p1).y * (m.p1 - l.p1).x) < EPS;
}

bool intersectLS(const Line& l, const Line& s) {
  return ((l.p2 - l.p1).x * (s.p1 - l.p1).y - (l.p2 - l.p1).y * (s.p1 - l.p1).x) * 
         ((l.p2 - l.p1).x * (s.p2 - l.p1).y - (l.p2 - l.p1).y * (s.p2 - l.p1).x) < -EPS;
}

bool intersectLP(const Line& l, const Point& p) {
  return fabs((l.p2 - p).x * (l.p1 - p).y - (l.p2 - p).y * (l.p1 - p).x) < EPS;
}

bool intersectSS(const Line& s, const Line& t) {
  return ccw(s.p1, s.p2, t.p1) * ccw(s.p1, s.p2, t.p2) <= 0 &&
         ccw(t.p1, t.p2, s.p1) * ccw(t.p1, t.p2, s.p2) <= 0;
}

bool intersectSP(const Line& s, const Point& p) {
  return fabs(s.p1 - p) + fabs(s.p2 - p) - fabs(s.p2 - s.p1) < EPS;
}

Point projection(const Line& l, const Point& p) {
  double t = ((p - l.p1).x * (l.p1 - l.p2).x + (p - l.p1).y * (l.p1 - l.p2).y) / ((l.p1 - l.p2).x * (l.p1 - l.p2).x + (l.p1 - l.p2).y * (l.p1 - l.p2).y);
  return l.p1 + (l.p1 - l.p2) * t;
}

double distanceLP(const Line& l, const Point& p) {
  return fabs(p - projection(l, p));
}

Point crosspoint(const Line& l, const Line& m) {