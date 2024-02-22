#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;
flt inv_vf[MAXN], cache[MAXN];
bool in_cache[MAXN];

flt calc(flt W) {
  if (in_cache[int(W * 10)]) return cache[int(W * 10)];
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    flt f = need * inv_vf[i];
    cost += f * pf[i];
  }
  in_cache[int(W * 10)] = true;
  return cache[int(W * 10)] = cost;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (cin >> N && N) {
    cin >> pw;
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
      inv_vf[i] = 1.0 / vf[i];
    }
    fill_n(in_cache, MAXN, false);
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
    cout << fixed << setprecision(10) << calc(left) << '\n';
  }
  return 0;
}