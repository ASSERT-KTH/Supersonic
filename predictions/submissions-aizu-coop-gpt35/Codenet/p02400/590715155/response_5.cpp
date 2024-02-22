#include <cstdio>

int main() {
  const double PI = 3.141592653589;
  double r;
  scanf("%lf", &r);
  
  double area = PI * r * r;
  double circumference = 2 * PI * r;
  
  printf("%lf %lf\n", area, circumference);
  
  return 0;
}