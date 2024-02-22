#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double Wvw = W * vw[i]; // Store the result of W * vw[i] in a variable
    if (Wvw > th[i])
      continue;
    double sum1 = th[i] - Wvw; // Use the stored result
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (1) {
    scanf("%d %d", &n, &pw); // Replace cin with scanf
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%lf %lf %lf %lf", &vw[i], &pf[i], &vf[i], &th[i]); // Replace cin with scanf
    double l = 0, r = inf;
    double resl = f(l), res1, res2; // Store the result of f(l) in a variable
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      res1 = f(m1);
      res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
      resl = res1; // Update the stored result
    }
    printf("%.4f\n", resl); // Use the stored result
  }
  return 0;
}