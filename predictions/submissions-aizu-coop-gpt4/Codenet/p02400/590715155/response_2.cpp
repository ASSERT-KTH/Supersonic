#include <cstdio>
using namespace std;

int main() {
  const double PI = 3.141592653589;
  double r;
  scanf("%lf", &r);
  double pi_r = PI * r; // Store the value of PI*r
  printf("%lf %lf\n", pi_r * r, 2 * pi_r);
  return 0;
}