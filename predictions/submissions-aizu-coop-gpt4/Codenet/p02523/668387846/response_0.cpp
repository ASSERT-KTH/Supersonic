#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  // Rename P1 and P2 to point1 and point2 for better readability.
  complex<double> point1, point2;

  // Input the real and imaginary parts of the complex numbers.
  cin >> point1.real() >> point1.imag() >> point2.real() >> point2.imag();

  // Calculate and print the distance between the two points.
  // The precision of the output is set to 5 decimal places.
  printf("%.5f\n", abs(point1 - point2));

  return 0;
}