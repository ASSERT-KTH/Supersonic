#include <cstdio>

int main() {
  double r;
  scanf("%lf", &r);

  double pi = 3.14159;
  double area = r * r * pi;
  double circumference = 2 * r * pi;
  
  printf("%.8lf %.8lf\n", area, circumference);
}