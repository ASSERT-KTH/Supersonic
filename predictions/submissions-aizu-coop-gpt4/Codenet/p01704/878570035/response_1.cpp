#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    flt left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;

      // Inlined 'calc' function
      flt cost1 = m1 * pw, cost2 = m2 * pw;
      for (int i = 0; i < N; i += 2) {  // Unrolled loop
        flt need1 = th[i] - m1 * vw[i];
        if (need1 > 0) {
          flt f1 = need1 / vf[i];
          cost1 += f1 * pf[i];
        }
        if (i + 1 < N) {
          flt need2 = th[i + 1] - m1 * vw[i + 1];
          if (need2 > 0) {
            flt f2 = need2 / vf[i + 1];
            cost1 += f2 * pf[i + 1];
          }
        }
        need1 = th[i] - m2 * vw[i];
        if (need1 > 0) {
          flt f1 = need1 / vf[i];
          cost2 += f1 * pf[i];
        }
        if (i + 1 < N) {
          flt need2 = th[i + 1] - m2 * vw[i + 1];
          if (need2 > 0) {
            flt f2 = need2 / vf[i + 1];
            cost2 += f2 * pf[i + 1];
          }
        }
      }

      if (cost1 < cost2)
        right = m2;
      else
        left = m1;
    }
    // Inlined 'calc' function for the final calculation
    flt cost = left * pw;
    for (int i = 0; i < N; ++i) {
      flt need = th[i] - left * vw[i];
      if (need > 0) {
        flt f = need / vf[i];
        cost += f * pf[i];
      }
    }
    printf("%.10f\n", cost);
  }
  return 0;
}