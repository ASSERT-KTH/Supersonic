#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;
flt calc(flt W) {
  flt cost = W * pw;
  flt need, f, c;
  for (int i = 0; i < N; ++i) {
    need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    f = need / vf[i];
    c = f * pf[i];
    cost += c;
  }
  return cost;
}
int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    flt left = 0, right = INT_MAX, m1, m2, c1, c2;
    for (int _ = 0; _ < 200; ++_) {
      m1 = (left + left + right) / 3.0;
      m2 = (left + right + right) / 3.0;
      c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}