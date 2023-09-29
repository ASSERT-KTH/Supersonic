#include <algorithm>
#include <complex>
#include <vector>
using namespace std;
using Point = complex<double>;
using Plane = vector<Point>;

inline double cross_prod(const Point &a, const Point &b) { return imag(conj(a) * b); }
inline double dot_prod(const Point &a, const Point &b) { return real(conj(a) * b); }

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

inline CCWiseState ccwise(Point a, Point b, Point c) {
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
  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    return !printf("NO\n");
  }
  printf("YES\n");
  return 0;
}

int main() {
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}