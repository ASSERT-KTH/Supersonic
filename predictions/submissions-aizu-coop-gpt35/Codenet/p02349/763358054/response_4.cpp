#include <iostream>
#include <vector>

typedef long long ll;

const int maxn = 100005;
std::vector<ll> S(maxn);

int main() {
  int n, q;
  std::cin >> n >> q;

  for (int i = 0; i < q; ++i) {
    bool op;
    std::cin >> op;

    if (op) {
      int k;
      std::cin >> k;

      int ans = 0;
      for (int j = k; j > 0; j -= j & -j)
        ans += S[j];

      std::cout << ans << '\n';
    } else {
      int s, t, x;
      std::cin >> s >> t >> x;

      for (int j = s; j <= n; j += j & -j)
        S[j] += x;

      for (int j = t + 1; j <= n; j += j & -j)
        S[j] -= x;
    }
  }

  return 0;
}