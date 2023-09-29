#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX 100001

double vw[MAX], pf[MAX], vf[MAX], th[MAX];
int n;
double pw;

inline double cost(double W) {
  double totalCost = W * pw;
  for (int i = 0; i < n; i++) {
    double sum1 = th[i] - W * vw[i];
    if (sum1 > 0) {
      double sum2 = sum1 / vf[i];
      totalCost += sum2 * pf[i];
    }
  }
  return totalCost;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  while (1) {
    std::cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (cost(m1) < cost(m2))
        r = m2;
      else
        l = m1;
    }
    std::cout << std::setprecision(4) << std::fixed << cost(l) << "\n";
  }
  return 0;
}