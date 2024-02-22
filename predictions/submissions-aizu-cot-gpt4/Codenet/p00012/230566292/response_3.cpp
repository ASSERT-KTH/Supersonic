#include <cstdio>
#include <vector>
using namespace std;

using Point = pair<double, double>;
using Plane = vector<Point>;

bool operator<(const Point &a, const Point &b) {
  return a.first != b.first ? a.first < b.first : a.second < b.second;
}

double cross_prod(const Point &a, const Point &b) { return a.first*b.second - a.second*b.first; }
double dot_prod(const Point &a, const Point &b) { return a.first*b.first + a.second*b.second; }

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(Point a, Point b, Point c) {
  b.first -= a.first; b.second -= a.second;
  c.first -= a.first; c.second -= a.second;
  double cross_prod_result = cross_prod(b, c);
  if (cross_prod_result > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross_prod_result < 0) {
    return CLOCKWISE;
  }
  double dot_prod_result = dot_prod(b, c);
  if (dot_prod_result < 0) {
    return ONLINE_BACK;
  } else if (b.first*b.first + b.second*b.second < c.first*c.first + c.second*c.second) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  Point A, B, C, P;
  if (scanf("%lf %lf", &A.first, &A.second) == EOF)
    return true;
  scanf("%lf %lf", &B.first, &B.second);
  scanf("%lf %lf", &C.first, &C.second);
  scanf("%lf %lf", &P.first, &P.second);
  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    printf("NO\n");
    return false;
  }
  printf("YES\n");
  return false;
}

int main() {
  while (!testcase_ends());
  return 0;
}