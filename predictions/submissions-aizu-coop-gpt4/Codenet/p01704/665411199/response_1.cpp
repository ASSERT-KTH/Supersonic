#include <cstdio> // for printf and scanf
#include <cmath>  // for INFINITY
#define MAX 100001

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double Wvw = W * vw[i]; // Compute it once
    if (Wvw > th[i])
      continue;
    double sum1 = th[i] - Wvw;
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (1) {
    scanf("%d%d", &n, &pw); // Use scanf instead of cin
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &vw[i], &pf[i], &vf[i], &th[i]); // Use scanf instead of cin
    double l = 0, r = INFINITY; // Use INFINITY from cmath
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}