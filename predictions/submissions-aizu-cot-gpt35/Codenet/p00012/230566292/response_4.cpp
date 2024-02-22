#include <cstdio>
#include <complex>
#include <vector>

using Point = std::complex<double>;

double cross_prod(const Point& a, const Point& b) {
  return (a.real() * b.imag()) - (a.imag() * b.real());
}

double dot_prod(const Point& a, const Point& b) {
  return (a.real() * b.real()) + (a.imag() * b.imag());
}

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(const Point& a, const Point& b, const Point& c) {
  Point b_minus_a = b - a;
  Point c_minus_a = c - a;
  double cross_product = cross_prod(b_minus_a, c_minus_a);
  double dot_product = dot_prod(b_minus_a, c_minus_a);

  if (cross_product > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross_product < 0) {
    return CLOCKWISE;
  } else if (dot_product < 0) {
    return ONLINE_BACK;
  } else if (norm(b_minus_a) < norm(c_minus_a)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) == EOF) {
    return true;
  }
  Point A(x, y);
  scanf("%lf %lf", &x, &y);
  Point B(x, y);
  scanf("%lf %lf", &x, &y);
  Point C(x, y);
  scanf("%lf %lf", &x, &y);
  Point P(x, y);

  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    printf("NO\n");
  } else {
    printf("YES\n");
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