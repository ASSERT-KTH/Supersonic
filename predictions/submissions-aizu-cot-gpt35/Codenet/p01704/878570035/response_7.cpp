#include <cstdio>
#include <climits>
#include <cmath>

const int MAXN = 100000 + 10;
const float eps = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

float calc(float W) {
  float cost = W * pw;
  for (int i = 0; i < N; ++i) {
    float need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    float f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N > 0) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    float left = 0, right = FLT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      float m1 = (2 * left + right) / 3.0;
      float m2 = (left + 2 * right) / 3.0;
      float c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}