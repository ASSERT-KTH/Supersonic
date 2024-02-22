#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;
const double eps = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, power;

double calc(double W) {
  double cost = W * power;
  for (int i = 0; i < N; ++i) {
    double need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    double f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &power);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    double left = 0, right = INT_MAX;
    while (right - left > eps) {
      double m1 = left + (right - left) / 3.0;
      double m2 = right - (right - left) / 3.0;
      double c1 = calc(m1), c2 = calc(m2);
      right = (c1 < c2) ? m2 : right;
      left = (c1 < c2) ? left : m1;
    }
    cout << fixed;
    cout.precision(10);
    cout << calc(left) << endl;
  }
  return 0;
}