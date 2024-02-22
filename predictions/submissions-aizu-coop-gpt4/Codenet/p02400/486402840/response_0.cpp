#include <cstdio>
#define PI 3.141592653589793238

int main() {
  double r, s, l;
  scanf("%lf", &r);
  s = r * r * PI;
  l = 2 * PI * r;
  printf("%.8lf %.8lf\n", s, l);
  return 0;
}