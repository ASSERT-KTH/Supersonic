#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

typedef double flt;

flt calc(const vector<int>& vw, const vector<int>& pf, const vector<int>& vf, const vector<int>& th, flt W) {
  flt cost = W * pw;
  for (int i = 0; i < vw.size(); ++i) {
    flt need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    flt f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  int N, pw;
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);

    vector<int> vw(N), pf(N), vf(N), th(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &vw[i], &pf[i], &vf[i], &th[i]);
    }

    flt left = 0, right = numeric_limits<flt>::max();
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(vw, pf, vf, th, m1);
      flt c2 = calc(vw, pf, vf, th, m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }

    printf("%.10f\n", calc(vw, pf, vf, th, left));
  }
  return 0;
}