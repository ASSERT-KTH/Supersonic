#include <cmath>
#include <iostream>
using namespace std;
int main() {
  double P1_real, P1_imag, P2_real, P2_imag;
  cin >> P1_real >> P1_imag >> P2_real >> P2_imag;
  printf("%.5f\n", sqrt(pow(P1_real - P2_real, 2) + pow(P1_imag - P2_imag, 2)));
  return 0;
}