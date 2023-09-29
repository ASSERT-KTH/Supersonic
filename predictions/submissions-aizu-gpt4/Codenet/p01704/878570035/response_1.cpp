#include <cstdio>
#include <algorithm>
#include <climits>

#define MAXN 100000 + 10

typedef long long LL;
typedef double flt;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = std::max(static_cast<flt>(0.0), th[i] - W * vw[i]);
    if (need > 0) {
        flt f = need / vf[i];
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
    flt left = 0, right = INT_MAX;
    while(std::fabs(right - left) > 1e-7){
      flt m1 = (left * 2 + right) / 3.0;
      flt m2 = (left + 2 * right) / 3.0;
      (calc(m1) < calc(m2))? right = m2 : left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}