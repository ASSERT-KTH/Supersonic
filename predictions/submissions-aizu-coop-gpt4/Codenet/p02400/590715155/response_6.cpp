#include <cstdio>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // turn off synchronization
  const double PI = 3.141592653589; // define PI as a constant
  double r, PI_r;
  scanf("%lf", &r); // use scanf for input
  PI_r = PI * r;    // calculate PI*r once
  printf("%lf %lf\n", PI_r * r, 2 * PI_r); // use printf for output
  return 0;
}