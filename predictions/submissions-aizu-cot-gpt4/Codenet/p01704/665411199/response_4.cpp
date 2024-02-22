#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>

using namespace std;

double f(int n, double pw, double* vw, double* pf, double* vf, double* th, double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    double sum1 = th[i] - W * vw[i];
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double pw;
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    double vw[n], pf[n], vf[n], th[n];
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = numeric_limits<double>::max();
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(n, pw, vw, pf, vf, th, m1);
      double res2 = f(n, pw, vw, pf, vf, th, m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(n, pw, vw, pf, vf, th, l));
  }
  return 0;
}