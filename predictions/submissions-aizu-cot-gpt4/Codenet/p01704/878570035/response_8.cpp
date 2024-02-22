#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const flt eps = 1e-7;
int *vw, *pf, *vf, *th;
flt *vwW;
int N, pw;
flt calc(flt W) {
  for (int i = 0; i < N; ++i) vwW[i] = W * vw[i];  // move out of loop
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = th[i] - vwW[i];  // use precalculated value
    if (need > 0) {
      flt f = need * vf[i];  // multiply instead of divide
      cost += f * pf[i];
    }
  }
  return cost;
}
int main() {
  while (scanf("%d", &N) == 1 && N) {
    vw = new int[N]; pf = new int[N]; vf = new int[N]; th = new int[N]; vwW = new flt[N];  // dynamic allocation
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
      vf[i] = 1.0 / vf[i];  // reciprocal
    }
    flt left = 0, right = INT_MAX;
    flt c1, c2;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      c1 = calc(m1); c2 = calc(m2);
      if (c1 < c2) right = m2;
      else left = m1;
    }
    printf("%.10f\n", c1);  // reuse calculated value
    delete[] vw; delete[] pf; delete[] vf; delete[] th; delete[] vwW;  // free memory
  }
  return 0;
}