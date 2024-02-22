#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
flt wv[MAXN]; // pre-computed values
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = th[i] - wv[i]; // using pre-computed value
    if (need <= 0)
      continue;
    flt f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  while (cin >> N && N) {
    cin >> pw;
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    flt left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      for (int i = 0; i < N; ++i) {
        wv[i] = m1 * vw[i]; // pre-computing values before entering calc()
      }
      flt c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    cout << fixed << setprecision(10) << calc(left) << "\n";
  }
  return 0;
}