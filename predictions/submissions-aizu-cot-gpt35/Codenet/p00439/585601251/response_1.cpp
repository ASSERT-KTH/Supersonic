#include <cstdio>
#include <climits>
#include <vector>

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k), n) {
    std::vector<long long> ac(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &ac[i]);
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    for (int i = k; i <= n; ++i) {
      if (ac[i] - ac[i - k] > res) {
        res = ac[i] - ac[i - k];
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}