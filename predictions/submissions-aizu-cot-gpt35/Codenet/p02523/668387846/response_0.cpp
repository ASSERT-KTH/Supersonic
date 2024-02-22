#include <complex>
#include <cstdio>

int main() {
  double P1_real, P1_imag, P2_real, P2_imag;
  scanf("%lf %lf %lf %lf", &P1_real, &P1_imag, &P2_real, &P2_imag);
  double abs_diff = sqrt(pow(P1_real - P2_real, 2) + pow(P1_imag - P2_imag, 2));
  printf("%.5f\n", abs_diff);
  return 0;
}