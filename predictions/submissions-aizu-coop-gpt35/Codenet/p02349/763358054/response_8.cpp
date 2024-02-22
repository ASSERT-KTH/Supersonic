#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int64_t n, q;
  std::cin >> n >> q;

  std::vector<int64_t> S(n + 1);

  for (int64_t i = 0; i < q; i++) {
    int op;
    std::cin >> op;
    if (op) {
      int k;
      std::cin >> k;
      int64_t ans = 0;
      for (int j = k; j > 0; j -= j & -j)
        ans += S[j];
      std::cout << ans << '\n';
    } else {
      int s, t, x;
      std::cin >> s >> t >> x;
      for (int j = s; j <= n; j += j & -j)
        S[j] += x;
      for (int j = t + 1; j <= n; j += j & -j)
        S[j] += -x;
    }
  }

  return 0;
}