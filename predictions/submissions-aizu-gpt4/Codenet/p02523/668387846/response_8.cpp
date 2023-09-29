#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
int main() {
  double p1r, p1i, p2r, p2i;
  cin >> p1r >> p1i >> p2r >> p2i;
  printf("%.5f\n", hypot(p1r - p2r, p1i - p2i));
  return 0;
}