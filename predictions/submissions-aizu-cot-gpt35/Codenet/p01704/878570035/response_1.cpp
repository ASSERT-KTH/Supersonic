#include <cstdio>
#include <climits>

const int MAXN = 100000 + 10;
const double EPS = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

double calc(double W) {
  double cost = W * pw;
  double minF = INT_MAX;
  for (int i = 0; i < N; ++i) {
    double need = th[i] - W * vw[i];
    if (need > 0) {
      double f = need / vf[i];
      if (f < minF) {
        minF = f;
      }
    }
  }
  cost += minF * pf[0];
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    double left = 0, right = INT_MAX;
    double result = 0;
    while (right - left > EPS) {
      double mid = (left + right) / 2.0;
      double c1 = calc(mid);
      double c2 = calc(mid + EPS);
      if (c1 < c2) {
        right = mid;
        result = c1;
      } else {
        left = mid;
        result = c2;
      }
    }
    printf("%.10f\n", result);
  }
  return 0;
}