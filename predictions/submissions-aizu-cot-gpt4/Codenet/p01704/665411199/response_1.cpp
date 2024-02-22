#include <iostream>
#include <cstdio>

#define MAX 100001
#define inf 1e9

double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W, int n, int pw) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double temp = W * vw[i];
    if (temp > th[i])
      continue;
    double sum1 = th[i] - temp;
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  int n, pw;
  while (1) {
    std::cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1, n, pw);
      double res2 = f(m2, n, pw);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l, n, pw));
  }
  return 0;
}