#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  static constexpr double PI = 3.141592653589;
  double r;
  cin >> r;
  const double r_squared = r * r;
  printf("%lf %lf\n", PI * r_squared, 2.0 * PI * r);
  return 0;
}