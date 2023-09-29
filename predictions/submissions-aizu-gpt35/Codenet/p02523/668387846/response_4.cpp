#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.5f\n", sqrt((a - c) * (a - c) + (b - d) * (b - d)));
  return 0;
}