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
  double cross = cross_prod(b, c);
  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot_prod(b, c) < 0) {
    return ONLINE_BACK;
  } else if (norm(b) < norm(c)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

int main() {
  double x, y;
  int solved = 0;
  while (scanf("%lf %lf", &x, &y) != EOF) {
    Point A(x, y);
    scanf("%lf %lf", &x, &y);
    Point B(x, y);
    scanf("%lf %lf", &x, &y);
    Point C(x, y);
    scanf("%lf %lf", &x, &y);
    Point P(x, y);
    CCWiseState tmp = ccwise(A, P, B);
    if (tmp != ccwise(B, P, C)) {
      printf("NO\n");
    } else if (tmp != ccwise(C, P, A)) {
      printf("NO\n");
    } else {
      printf("YES\n");
      ++solved;
    }
  }
  return !solved;
}