#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double p1_real, p1_imag, p2_real, p2_imag;
  cin >> p1_real >> p1_imag >> p2_real >> p2_imag;
  double dist = sqrt(pow(p1_real - p2_real, 2) + pow(p1_imag - p2_imag, 2));
  printf("%.5f\n", dist);
  return 0;
}