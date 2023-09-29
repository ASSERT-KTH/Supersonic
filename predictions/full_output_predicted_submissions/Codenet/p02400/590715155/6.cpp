#include <iostream>
using namespace std;
int main() {
  double PI = 3.141592653589;
  double r;
  cin >> r;
  printf("%lf %lf\n", PI * r * r, 2 * PI * r);
  return 0;
}
