#include <iostream>
#include <array>
#include <cmath>

constexpr int MAX = 100001;
constexpr double inf = 1e9;

int n, pw;
std::array<double, MAX> vw, pf, vf, th;

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; ++i) {
    double sum1 = th[i] - W * vw[i];
    if (sum1 <= 0)
      continue;
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  while (std::cin >> n >> pw && n != 0) {
    for (int i = 0; i < n; ++i)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; ++i) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      l = res1 < res2 ? m1 : l;
      r = res1 < res2 ? r : m2;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}