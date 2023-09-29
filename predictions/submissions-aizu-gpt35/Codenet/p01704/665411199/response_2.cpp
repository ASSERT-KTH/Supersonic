#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX], m1, m2, res1, res2;
double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double prod = W * vw[i];
    if (prod <= th[i]) {
      double sum1 = th[i] - prod;
      double sum2 = sum1 / vf[i];
      cost += sum2 * pf[i];
    }
  }
  return cost;
}
int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0) break;
    for (int i = 0; i < n; i++) cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      m1 = (l * 2.0 + r) / 3.0;
      m2 = (l + r * 2.0) / 3.0;
      res1 = f(m1);
      res2 = f(m2);
      if (res1 < res2) r = m2;
      else l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}