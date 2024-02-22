#include <complex>
#include <iostream>
using namespace std;

static const double EPS = 1e-12;

using Point = complex<double>;

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
  ON_SEGMENT,
  ONLINE_FRONT,
  CLOCKWISE,
  ONLINE_BACK,
  COUNTER_CLOCKWISE,
};

CCWiseState ccwise(const Point &a, const Point &b, const Point &c) {
  Point b_minus_a = b - a;
  Point c_minus_a = c - a;

  double cross = cross_prod(b_minus_a, c_minus_a);
  double dot = dot_prod(b_minus_a, c_minus_a);

  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (norm(b_minus_a) < norm(c_minus_a)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (!(cin >> x >> y)) {
    return true;
  }
  Point A(x, y);

  cin >> x >> y;
  Point B(x, y);

  cin >> x >> y;
  Point C(x, y);

  cin >> x >> y;
  Point P(x, y);

  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }

  return false;
}

int main() {
  int solved = 0;
  while (!testcase_ends()) {
    ++solved;
  }
  return !solved;
}