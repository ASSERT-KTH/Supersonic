#include <cstdio>
#include <cmath>

int main() {
  const double PI = M_PI;
  double r;
  scanf("%lf", &r);
  printf("%lf %lf\n", PI * r * r, 2 * PI * r);
}