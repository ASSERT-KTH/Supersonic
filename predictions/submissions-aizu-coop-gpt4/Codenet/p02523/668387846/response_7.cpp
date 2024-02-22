#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double real1, imag1, real2, imag2;  // Declare temporary variables for real and imaginary parts

  // Correctly read the real and imaginary parts of the complex numbers
  cin >> real1 >> imag1 >> real2 >> imag2;

  // Construct the complex numbers using the read values
  complex<double> P1(real1, imag1);
  complex<double> P2(real2, imag2);

  // Print the absolute difference between the complex numbers
  printf("%.5f\n", abs(P1 - P2));

  return 0;
}