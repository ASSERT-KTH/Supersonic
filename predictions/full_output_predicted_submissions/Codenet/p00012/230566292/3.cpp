#include <algorithm>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;
static const double EPS = 1e-12;
static const double INF = 1e24;
using Point = complex<double>;
using Plane = vector<Point>;
namespace std {
bool operator<(const Point &a, const Point &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
} // namespace std
double cross_prod(const Point &a, const Point &b) { return imag(conj(a) * b); }
double dot_prod(const Point &a, const Point &b) { return real(conj(a) * b); }
struct Line : public pair<Point, Point> {
  Line() {}
  Line(const Point &a, const Point &b) {
    first = a;
    second = b;
  }
};
struct LineSeg : public pair<Point, Point> {
  LineSeg() {}
  LineSeg(const Point &a, const Point &b) {
    first = a;
    second = b;
  }
};
struct Circle {
  Point p;
  double r;
  Circle() {}
  Circle(const Point &p, const double r) : p(p), r(r) {}
};
enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};
CCWiseState ccwise(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross_prod(b, c) > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross_prod(b, c) < 0) {
    return CLOCKWISE;
  } else if (dot_prod(b, c) < 0) {
    return CLOCK