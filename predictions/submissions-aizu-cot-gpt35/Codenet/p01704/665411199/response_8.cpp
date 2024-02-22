#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

const double inf = std::numeric_limits<double>::infinity();

double calculateCost(int n, int pw, double* vw, double* pf, double* vf, double* tw) {
  double cost = 0;
  for (int i = 0; i < n; i++) {
    if (vw[i] > tw[i])
      continue;
    double sum1 = tw[i] - vw[i];
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost + pw * tw[n];
}

double ternarySearch(int n, int pw, double* vw, double* pf, double* vf, double* tw) {
  double l = 0, r = inf;
  const double eps = 1e-9;
  while (r - l > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double res1 = calculateCost(n, pw, vw, pf, vf, &m1);
    double res2 = calculateCost(n, pw, vw, pf, vf, &m2);
    if (res1 < res2)
      r = m2;
    else
      l = m1;
  }
  return calculateCost(n, pw, vw, pf, vf, &l);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  while (true) {
    int n, pw;
    std::cin >> n >> pw;
    if (n == 0)
      break;
    double vw[n], pf[n], vf[n], tw[n];
    for (int i = 0; i < n; i++)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> tw[i];
    double result = ternarySearch(n, pw, vw, pf, vf, tw);
    std::cout << std::fixed << std::setprecision(4) << result << std::endl;
  }
  return 0;
}