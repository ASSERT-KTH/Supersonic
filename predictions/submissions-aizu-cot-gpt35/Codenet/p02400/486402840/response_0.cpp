#include <cmath>
#include <cstdio>

int main() {
  double r, s, l;
  scanf("%lf", &r);
  s = M_PI * r * r;
  l = 2 * M_PI * r;
  printf("%.8f %.8f\n", s, l);
}