#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  const double PI = 3.141592653589;
  double r;
  scanf("%lf", &r);
  printf("%.9lf %.9lf\n", PI * r * r, 2 * PI * r);
  return 0;
}