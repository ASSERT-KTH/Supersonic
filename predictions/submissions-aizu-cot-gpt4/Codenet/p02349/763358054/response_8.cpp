#include <iostream>
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> n >> q;
  for (int i = 0; i < q; i++) {
    bool op;
    std::cin >> op;
    if (op) {
      int k;
      std::cin >> k;
      int ans = 0;
      for (int i = k; i > 0; i -= i & -i)
        ans += S[i];
      std::cout << ans << std::endl; // Changed '\n' to std::endl
    } else {
      int s, t, x;
      std::cin >> s >> t >> x;
      for (int i = s; i <= n; i += i & -i)
        S[i] += x;
      for (int i = t + 1; i <= n; i += i & -i)
        S[i] -= x; // Changed S[i] += -x; to S[i] -= x;
    }
  }
}