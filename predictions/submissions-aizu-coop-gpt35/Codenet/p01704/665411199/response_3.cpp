#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;

int n, pw;
vector<double> vw(MAX), pf(MAX), vf(MAX), th(MAX);

double f(double W) {
  double cost = W * pw;
  double vw_i, th_i, sum1, sum2;
  for (int i = 0; i < n; i++) {
    vw_i = vw[i];
    th_i = th[i];
    if (W * vw_i > th_i)
      continue;
    sum1 = th_i - W * vw_i;
    sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i += 2) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
      m1 = (l * 2.0 + r) / 3.0;
      m2 = (l + r * 2.0) / 3.0;
      res1 = f(m1);
      res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}