#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  vector<ll> S(n+1, 0);

  for (int i = 0; i < q; i++) {
    bool op;
    scanf("%d", &op);

    if (op) {
      int k;
      scanf("%d", &k);
      ll ans = 0;

      for (int i = k; i > 0; i -= i & -i)
        ans += S[i];

      printf("%lld\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);

      for (int i = s; i <= n; i += i & -i)
        S[i] += x;

      for (int i = t + 1; i <= n; i += i & -i)
        S[i] += -x;
    }
  }

  return 0;
}