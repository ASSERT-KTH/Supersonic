#include <iostream>
#include <limits>
using namespace std;

const int MAXN = 100000 + 10;
const double eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;
double calc(double W, const double* reciprocals) {
  double cost = W * pw;
  for (int i = 0; i < N; ++i) {
    double need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    double f = need * reciprocals[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while (cin >> N && N) {
    cin >> pw;
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    double left = 0, right = numeric_limits<double>::max();
    double reciprocals[MAXN];
    for (int i = 0; i < N; ++i) {
      reciprocals[i] = 1.0 / vf[i];
    }
    for (int _ = 0; _ < 200; ++_) {
      double m1 = (left + left + right) / 3.0;
      double m2 = (left + right + right) / 3.0;
      double c1 = calc(m1, reciprocals);
      double c2 = calc(m2, reciprocals);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    cout.precision(10);
    cout << fixed << calc(left, reciprocals) << endl;
  }
  
  return 0;
}