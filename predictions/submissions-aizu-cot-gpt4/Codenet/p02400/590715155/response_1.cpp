#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  const double PI = 3.141592653589;
  double r;
  cin >> r;
  double pi_r = PI * r;  // Calculate PI * r once and store it in a variable.
  printf("%lf %lf\n", pi_r * r, 2 * pi_r);  // Use the stored value in the calculations.
  return 0;
}