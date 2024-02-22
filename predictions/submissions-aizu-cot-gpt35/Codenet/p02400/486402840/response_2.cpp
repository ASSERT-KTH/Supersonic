#include <cstdio>

int main() {
  double r, s, l;
  scanf("%lf", &r);
  s = r * r * 3.141592653589;
  l = 3.141592653589 * (r + r);
  printf("%.8lf %.8lf\n", s, l);
}