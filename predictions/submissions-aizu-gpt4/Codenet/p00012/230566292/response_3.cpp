#include <cstdio>
#include <complex>

using namespace std;
using Point = complex<double>;

static inline double cross_prod(const Point &a, const Point &b) { return imag(conj(a) * b); }
static inline double dot_prod(const Point &a, const Point &b) { return real(conj(a) * b); }

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

static inline CCWiseState ccwise(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  const double cross = cross_prod(b, c);
  const double dot = dot_prod(b, c);
  const double norm_b = norm(b);
  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (norm_b < norm(c)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) == EOF)
    return 1;
  Point A(x, y);
  scanf("%lf %lf", &x, &y);
  Point B(x, y);
  scanf("%lf %lf", &x, &y);
  Point C(x, y);
  scanf("%lf %lf", &x, &y);
  Point P(x, y);
  const CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    return !printf("NO\n");
  }
  printf("YES\n");
  return 0;
}

int main() {
  while (!testcase_ends()) {}
  return 0;
}