#include <cstdio>
#define PI 3.141592653589

int main() {
  double r, s;
  scanf("%lf", &r);
  s = r * r * PI;
  printf("%.8lf %.8lf\n", s, 2 * r * PI);
}