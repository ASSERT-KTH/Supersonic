#include <iostream>
#include <cstdio>
#define MAX 100001
#define inf 1e9
using namespace std;

int n, pw;
int vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    int Wvw = W * vw[i]; // Calculate once and store it in a variable
    if (Wvw > th[i])
      continue;
    int sum1 = th[i] - Wvw;
    double sum2 = sum1 * (1.0 / vf[i]); // Multiply by the reciprocal instead of division
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
    int numIterations = min(200, n); // Determine the number of iterations dynamically
    for (int i = 0; i < numIterations; i++) {
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