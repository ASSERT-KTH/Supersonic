#include <complex>

using namespace std;

using Point = complex<double>;

enum CCWiseState {
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
};

CCWiseState ccwise(Point a, Point b, Point c) {
  double crossProduct = imag(conj(b - a) * (c - a));
  if (crossProduct > 0) {
    return COUNTER_CLOCKWISE;
  } else if (crossProduct < 0) {
    return CLOCKWISE;
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
  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    printf("NO\n");
    return false;
  }
  printf("YES\n");
  return false;
}

int main() {
  while (!testcase_ends())
    ;
  return 0;
}