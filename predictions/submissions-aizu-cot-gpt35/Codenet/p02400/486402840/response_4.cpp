#include <cstdio>
#include <cmath>

int main() {
  double r, s, l;
  scanf("%lf", &r);
  s = M_PI * r * r;
  l = 2 * M_PI * r;
  printf("%.8lf %.8lf\n", s, l);
}