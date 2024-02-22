#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long n, q;
  scanf("%lld %lld", &n, &q);

  vector<long long> S(n + 1, 0);

  for (long long j = 0; j < q; j++) {
    bool op;
    scanf("%d", &op);

    if (op) {
      long long k;
      scanf("%lld", &k);

      long long ans = 0;
      for (long long i = k; i > 0; i -= i & -i)
        ans += S[i];

      printf("%lld\n", ans);
    } else {
      long long s, t, x;
      scanf("%lld %lld %lld", &s, &t, &x);

      for (long long i = s; i <= n; i += i & -i)
        S[i] += x;

      for (long long i = t + 1; i <= n; i += i & -i)
        S[i] += -x;
    }
  }

  return 0;
}