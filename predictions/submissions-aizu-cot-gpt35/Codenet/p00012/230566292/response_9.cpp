#include <complex>
#include <vector>
#include <cstdio>

static const double EPS = 1e-12;
static const double INF = 1e24;

using Point = std::complex<double>;
using Plane = std::vector<Point>;

double cross_prod(const Point& a, const Point& b) {
  return std::imag(std::conj(a) * b);
}

double dot_prod(const Point& a, const Point& b) {
  return std::real(std::conj(a) * b);
}

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(const Point& a, const Point& b, const Point& c, double b_cross_c, double b_dot_c) {
  if (b_cross_c > 0) {
    return COUNTER_CLOCKWISE;
  } else if (b_cross_c < 0) {
    return CLOCKWISE;
  } else if (b_dot_c < 0) {
    return ONLINE_BACK;
  } else if (std::norm(b) < std::norm(c)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (std::scanf("%lf %lf", &x, &y) == EOF)
    return true;

  Point A(x, y);
  std::scanf("%lf %lf", &x, &y);
  Point B(x, y);
  std::scanf("%lf %lf", &x, &y);
  Point C(x, y);
  std::scanf("%lf %lf", &x, &y);
  Point P(x, y);

  double b_cross_c = cross_prod(B - A, C - A);
  double b_dot_c = dot_prod(B - A, C - A);

  CCWiseState tmp = ccwise(A, P, B, b_cross_c, b_dot_c);
  if (tmp != ccwise(B, P, C, b_cross_c, b_dot_c)) {
    std::printf("NO\n");
  } else if (tmp != ccwise(C, P, A, b_cross_c, b_dot_c)) {
    std::printf("NO\n");
  } else {
    std::printf("YES\n");
  }

  return false;
}

int main() {
  while (!testcase_ends())
    ;

  return 0;
}