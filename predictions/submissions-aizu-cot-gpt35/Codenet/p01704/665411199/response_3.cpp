#include <iostream>
#include <iomanip>
#include <vector>

const int MAX = 100001;
const double inf = 1e9;

double f(double W, const std::vector<double>& vw, const std::vector<double>& pf, const std::vector<double>& vf, const std::vector<double>& th, int n, int pw) {
  double cost = W * pw;
  for (double w : vw) {
    if (W * w > th[i])
      continue;
    double sum1 = th[i] - W * w;
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (true) {
    int n, pw;
    std::cin >> n >> pw;
    if (n == 0)
      break;
    std::vector<double> vw(n), pf(n), vf(n), th(n);
    for (int i = 0; i < n; i++)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1, vw, pf, vf, th, n, pw);
      double res2 = f(m2, vw, pf, vf, th, n, pw);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    std::cout << std::fixed << std::setprecision(4) << f(l, vw, pf, vf, th, n, pw) << std::endl;
  }
  return 0;
}