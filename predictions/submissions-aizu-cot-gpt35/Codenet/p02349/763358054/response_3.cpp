#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<ll> S(n + 1, 0);

  for (int q = 0; q < q; ++q) {
    int op;
    scanf("%d", &op);

    if (op) {
      int k;
      scanf("%d", &k);

      ll ans = 0;
      for (int idx = k; idx > 0; idx -= idx & -idx)
        ans += S[idx];

      printf("%lld\n", ans);
    } else {
      int s, t, x;
      scanf("%d%d%d", &s, &t, &x);

      for (int idx = s; idx <= n; idx += idx & -idx)
        S[idx] += x;

      for (int idx = t + 1; idx <= n; idx += idx & -idx)
        S[idx] += -x;
    }
  }

  return 0;
}