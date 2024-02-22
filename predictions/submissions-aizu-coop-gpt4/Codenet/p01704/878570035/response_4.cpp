#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
flt vwW[MAXN]; // precomputed W * vw[i]
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    vwW[i] = W * vw[i]; // precompute W * vw[i]
    flt need = th[i] - vwW[i];
    if (need <= 0)
      continue;
    flt f = need / vf[i];
    cost += f * pf[i];
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
    flt c1 = calc((left + left + right) / 3.0); // store the results of the previous iteration
    flt c2 = calc((left + right + right) / 3.0);
    for (int _ = 0; _ < 199; ++_) { // one less iteration because we already did one before the loop
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      c1 = (m1 == vwW[0]) ? c1 : calc(m1); // reuse the results of the previous iteration
      c2 = (m2 == vwW[0]) ? c2 : calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}