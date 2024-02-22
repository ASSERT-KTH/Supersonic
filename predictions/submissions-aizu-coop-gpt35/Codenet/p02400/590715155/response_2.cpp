#include <cstdio>

constexpr double PI = 3.14159;

int main() {
  double r;
  scanf("%lf", &r);
  printf("%lf %lf\n", PI * r * r, 2 * PI * r);
  return 0;
}