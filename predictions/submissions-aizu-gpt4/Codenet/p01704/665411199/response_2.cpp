#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100001;
const double inf = 1e9;

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

inline double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; ++i) {
    double Wvw = W * vw[i];
    if (Wvw > th[i])
      continue;
    double sum1 = th[i] - Wvw;
    cost += (sum1 / vf[i]) * pf[i];
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> pw && n) {
    for (int i = 0; i < n; ++i)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; ++i) {
      double m1 = (2.0 * l + r) / 3.0;
      double m2 = (l + 2.0 * r) / 3.0;
      if (f(m1) < f(m2))
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}