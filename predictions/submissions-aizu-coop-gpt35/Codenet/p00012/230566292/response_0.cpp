#include <algorithm>
#include <complex>
#include <cstdio>
using namespace std;
static const double EPS = 1e-12;
static const double INF = 1e24;
using Point = complex<double>;

// Define a fixed-size array for the points A, B, C
using Plane = Point[3];

// Remove unnecessary operator< overload

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

// Modify ccwise function to eliminate redundant and unnecessary calculations
CCWiseState ccwise(const Point &a, const Point &b, const Point &c) {
  Point ab = b - a;
  Point ac = c - a;
  double cross = cross_prod(ab, ac);
  double dot = dot_prod(ab, ac);
  double norm_ab = norm(ab);
  double norm_ac = norm(ac);

  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (norm_ab < norm_ac) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;

  if (scanf("%lf %lf", &x, &y) == EOF)
    return true;
  Point A(x, y);

  scanf("%lf %lf", &x, &y);
  Point B(x, y);

  scanf("%lf %lf", &x, &y);
  Point C(x, y);

  scanf("%lf %lf", &x, &y);
  Point P(x, y);

  // Use the modified ccwise function
  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C)) {
    return !printf("NO\n");
  } else if (tmp != ccwise(C, P, A)) {
    return !printf("NO\n");
  }

  printf("YES\n");
  return false;
}

int main() {
  while (!testcase_ends())
    ;
  return 0;
}