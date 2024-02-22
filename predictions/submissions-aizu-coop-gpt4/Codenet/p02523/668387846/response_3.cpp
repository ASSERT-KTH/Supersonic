#include <cstdio>
#include <cmath>
int main() {
  double P1_real, P1_imag, P2_real, P2_imag;
  scanf("%lf %lf %lf %lf", &P1_real, &P1_imag, &P2_real, &P2_imag);
  printf("%.5f\n", hypot(P1_real - P2_real, P1_imag - P2_imag));
  return 0;
}