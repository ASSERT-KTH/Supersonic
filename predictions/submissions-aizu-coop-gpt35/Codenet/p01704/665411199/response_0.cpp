#include <bits/stdc++.h>
#define MAX 100001
#define inf INT_MAX

using namespace std;

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  if (W * vw[n-1] > th[n-1]) {
    return W * pw;
  }

  double cost = W * pw;
  for (int i = 0; i < n; i += 2) {
    if (W * vw[i] > th[i]) continue;

    double sum1 = th[i] - W * vw[i];
    double sum2 = sum1 / (double)vf[i];
    cost += sum2 * pf[i];

    if (i + 1 < n && W * vw[i+1] <= th[i+1]) {
      double sum3 = th[i+1] - W * vw[i+1];
      double sum4 = sum3 / (double)vf[i+1];
      cost += sum4 * pf[i+1];
    }
  }

  return cost;
}

int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }

    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2) {
        r = m2;
      } else {
        l = m1;
      }
    }

    printf("%.4f\n", f(l));
  }

  return 0;
}