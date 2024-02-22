#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 100001
#define inf 1e9

int n, pw;
std::vector<int> vw, pf, vf, th;

__attribute__((optimize("-O3")))
int f(int W) {
  int cost = W * pw;
  for (int i = 0; i < n && W * vw[i] <= th[i]; i++) {
    int sum1 = th[i] - W * vw[i];
    int sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (1) {
    std::cin >> n >> pw;
    if (n == 0)
      break;
    vw.resize(n);
    pf.resize(n);
    vf.resize(n);
    th.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = l + (r - l) / 3.0;
      double m2 = r - (r - l) / 3.0;
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