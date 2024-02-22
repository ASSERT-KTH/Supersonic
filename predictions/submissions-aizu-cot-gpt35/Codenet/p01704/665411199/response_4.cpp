#include <iostream>
#include <limits>
#define MAX 100001
using namespace std;

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W <= th[i] / vw[i]) {
      double sum1 = th[i] - W * vw[i];
      if (sum1 > 0) {
        double sum2 = sum1 / vf[i];
        cost += sum2 * pf[i];
      }
    }
  }
  return cost;
}

int main() {
  while (cin >> n >> pw && n != 0) {
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = numeric_limits<double>::infinity();
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    cout << fixed << setprecision(4) << f(l) << endl;
  }
  return 0;
}