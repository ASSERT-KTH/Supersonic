#include <iostream>
#include <cstdio>
#define MAX 100001
#define inf 1e9

double f(int n, double W, double* vw, double* pf, double* vf, double* th) {
  double cost = W * vw[n];
  for (int i = 0; i < n; ++i) {
    double wv = W * vw[i];
    if (wv > th[i]) 
      continue;
    else {
      double sum1 = th[i] - wv;
      double sum2 = sum1 / vf[i];
      cost += sum2 * pf[i];
    }
  }
  return cost;
}

int main() {
  int n, pw;
  double vw[MAX], pf[MAX], vf[MAX], th[MAX];
  while (1) {
    std::cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; ++i)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; ++i) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(n, m1, vw, pf, vf, th);
      double res2 = f(n, m2, vw, pf, vf, th);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(n, l, vw, pf, vf, th));
  }
  return 0;
}