#include <cstdio>
#include <climits>
#include <cmath>

constexpr int MAXN = 100000 + 10;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

inline double calc(double W) {
  double cost = W * pw;
  for (int i = 0; i < N; ++i) {
    double need = th[i] - W * vw[i];
    if (need > 0) {
      double f = need / vf[i];
      cost += f * pf[i];
    }
  }
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    double left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      double m1 = left + (right - left) / 3.0;
      double m2 = right - (right - left) / 3.0;
      double c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}