#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];
double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    double sum1 = th[i] - W * vw[i];
    double sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
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
    cout << fixed << setprecision(4) << f(l) << "\n";
  }
  return 0;
}