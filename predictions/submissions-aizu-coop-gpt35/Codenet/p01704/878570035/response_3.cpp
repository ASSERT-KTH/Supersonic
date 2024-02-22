#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
vector<int> vw, pf, vf, th;
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  flt need;
  for (int i = 0; i < N; ++i) {
    need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    flt f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    vw.resize(N);
    pf.resize(N);
    vf.resize(N);
    th.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &vw[i], &pf[i], &vf[i], &th[i]);
    }
    flt left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}