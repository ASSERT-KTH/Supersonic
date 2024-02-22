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
// ... (other code remains the same) ...
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
  if (tmp != ccwise(B, P, C)) {
    printf("NO\n");
    return 0;
  } else if (tmp != ccwise(C, P, A)) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}
int main() {
  if (!testcase_ends())
    return 0;
  return 1;
}