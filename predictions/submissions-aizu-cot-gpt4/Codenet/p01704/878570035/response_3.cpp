#include <cstdio>
#include <climits>

typedef long long LL;
typedef std::pair<int, int> PII;
typedef double flt;

const int MAXN = 100000 + 10;
const flt eps = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = th[i] - W * vw[i];
    if (need > 0) {
      flt f = need / vf[i];
      cost += f * pf[i];
    }
  }
  return cost;
}

int main() {
  do {
    std::scanf("%d", &N);
    if (N) {
      std::scanf("%d", &pw);
      for (int i = 0; i < N; ++i) {
        std::scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
      }
      flt left = 0, right = INT_MAX;
      for (int _ = 0; _ < 200; ++_) {
        flt m1 = (2 * left + right) / 3.0;
        flt m2 = (left + 2 * right) / 3.0;
        flt c1 = calc(m1), c2 = calc(m2);
        if (c1 < c2)
          right = m2;
        else
          left = m1;
      }
      printf("%.10f\n", calc(left));
    }
  } while (N != 0);
  return 0;
}