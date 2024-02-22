#include <cstdio>
#include <climits>
#include <algorithm>

typedef long long LL;
typedef std::pair<int, int> PII;
typedef double flt;

const int MAXN = 100000 + 10;
const flt eps = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

flt calc(flt W) {
  LL cost = static_cast<LL>(W * pw);
  for (int i = 0; i < N; i += 2) {
    flt need1 = th[i] - W * vw[i];
    flt need2 = th[i + 1] - W * vw[i + 1];
    if (need1 > 0) {
      LL f = static_cast<LL>(need1 / vf[i]);
      cost += f * pf[i];
    }
    if (need2 > 0) {
      LL f = static_cast<LL>(need2 / vf[i + 1]);
      cost += f * pf[i + 1];
    }
  }
  return static_cast<flt>(cost) / 3.0;
}

int main() {
  while (std::scanf("%d", &N) == 1 && N) {
    std::scanf("%d", &pw);
    for (int i = 0; i < N; i += 2) {
      std::scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
      std::scanf("%d%d%d%d", vw + i + 1, pf + i + 1, vf + i + 1, th + i + 1);
    }
    flt left = 0, right = INT_MAX;
    for (int iter = 0; iter < 200; ++iter) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    std::printf("%.10f\n", calc(left));
  }
  return 0;
}