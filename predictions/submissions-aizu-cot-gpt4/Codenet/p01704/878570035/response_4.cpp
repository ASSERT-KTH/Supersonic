#include <iostream>
#include <cstdio>
#include <algorithm>
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
  std::ios_base::sync_with_stdio(false);
  while (std::cin >> N && N) {
    std::cin >> pw;
    for (int i = 0; i < N; ++i) {
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    flt left = 0, right = INT_MAX, m1 = (left * 2 + right) / 3.0, m2 = (left + right * 2) / 3.0, c1 = calc(m1), c2;
    for (int _ = 0; _ < 200; ++_) {
      if (c1 < (c2 = calc(m2))) {
        right = m2;
        m2 = (left + right * 2) / 3.0;
      }
      else {
        left = m1;
        m1 = (left * 2 + right) / 3.0;
        c1 = calc(m1);
      }
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}