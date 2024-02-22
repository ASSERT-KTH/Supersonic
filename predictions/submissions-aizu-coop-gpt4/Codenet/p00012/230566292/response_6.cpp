#include <algorithm>
#include <complex>
#include <cstdio>
#include <vector>

static const double EPS = 1e-12;
static const double INF = 1e24;
using Point = std::complex<double>;
using Plane = std::vector<Point>;

bool operator<(const Point &a, const Point &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}

double cross_prod(const Point &a, const Point &b) { return imag(std::conj(a) * b); }
double dot_prod(const Point &a, const Point &b) { return real(std::conj(a) * b); }

struct Line : public std::pair<Point, Point> {
  Line() {}
  Line(const Point &a, const Point &b) {
    first = a;
    second = b;
  }
};

struct LineSeg : public std::pair<Point, Point> {
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
    return ONLINE_BACK;
  } else if (norm(b) < norm(c)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x1, y1, x2, y2, x3, y3, x4, y4;
  // Combine scanf calls
  if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == EOF)
    return 1;
  Point A(x1, y1), B(x2, y2), C(x3, y3), P(x4, y4);
  
  CCWiseState tmp = ccwise(A, P, B);
  CCWiseState tmp1 = ccwise(B, P, C);
  CCWiseState tmp2 = ccwise(C, P, A);
  
  if (tmp != tmp1 || tmp != tmp2) {
    printf("NO\n");
    return true;
  }
  
  printf("YES\n");
  return false;
}

int main() {
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}