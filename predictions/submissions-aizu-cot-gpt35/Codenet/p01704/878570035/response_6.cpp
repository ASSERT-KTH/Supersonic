#include <iostream>
#include <array>
#include <limits>

using std::scanf;
using std::printf;

using flt = double;

flt calc(const flt& W, const std::array<int, MAXN>& vw, const std::array<int, MAXN>& pf, const std::array<int, MAXN>& vf, const std::array<int, MAXN>& th, const int& N, const int& pw) {
  flt cost = W * pw;
  for (int i = N - 1; i >= 0; --i) {
    flt need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    flt f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  int N;
  while (scanf("%d", &N) != EOF && N) {
    int pw;
    scanf("%d", &pw);
    std::array<int, MAXN> vw, pf, vf, th;
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &vw[i], &pf[i], &vf[i], &th[i]);
    }
    flt left = 0, right = std::numeric_limits<flt>::max();
    int maxIterations = std::min(N * 100, 200);
    for (int _ = 0; _ < maxIterations; --_) {
      flt m1 = (2 * left + right) / 3.0;
      flt m2 = (left + 2 * right) / 3.0;
      flt c1 = calc(m1, vw, pf, vf, th, N, pw);
      flt c2 = calc(m2, vw, pf, vf, th, N, pw);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left, vw, pf, vf, th, N, pw));
  }
  return 0;
}