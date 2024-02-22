#include <iostream>
#include <cstdio>
#define MAX 1000
#define inf 1e18

using namespace std;

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double wv = W * vw[i];
    if (wv > th[i])
      continue;
    double sum1 = th[i] - wv;
    double sum2 = sum1 * (1.0 / vf[i]);
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
    double diff = (r - l) / 3.0;
    while (diff > 1e-9) {
      double m1 = l + diff;
      double m2 = r - diff;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
      diff = (r - l) / 3.0;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}