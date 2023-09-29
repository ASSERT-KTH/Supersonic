#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double real1, imag1, real2, imag2;
  cin >> real1 >> imag1 >> real2 >> imag2;
  printf("%.5f\n", sqrt((real1-real2)*(real1-real2) + (imag1-imag2)*(imag1-imag2)));
  return 0;
}