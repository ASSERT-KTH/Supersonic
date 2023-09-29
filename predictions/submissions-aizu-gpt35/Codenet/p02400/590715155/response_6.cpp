#include <cstdio>
#include <iostream>
using namespace std;
const double PI = 3.141592653589;
int main() {
  double r;
  scanf("%lf", &r);
  printf("%lf %lf\n", PI * r * r, 2 * PI * r);
  return 0;
}