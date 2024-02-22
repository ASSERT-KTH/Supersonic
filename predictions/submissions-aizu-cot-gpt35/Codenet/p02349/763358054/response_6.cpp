#include <iostream>
#include <cstring>

typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

int main() {
  std::ios_base::sync_with_stdio(false);
  
  std::cin >> n >> q;

  memset(S, 0, sizeof(S));

  for (int queryIndex = 0; queryIndex < q; ++queryIndex) {
    int op;
    std::cin >> op;

    if (op) {
      int k;
      std::cin >> k;

      int ans = 0;
      while (k > 0) {
        ans += S[k];
        k -= k & -k;
      }
      std::cout << ans << std::endl;
    } else {
      int s, t, x;
      std::cin >> s >> t >> x;

      for (int index = s; index <= n; index += index & -index)
        S[index] += x;

      for (int index = t + 1; index <= n; index += index & -index)
        S[index] -= x;
    }
  }

  return 0;
}