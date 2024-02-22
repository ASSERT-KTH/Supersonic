#include <algorithm>
#include <vector>
#include <cstdio>

constexpr int INF = 2000000000;

int main() {
  int n, m;
  std::scanf("%d %d", &n, &m);

  std::vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) {
    std::scanf("%d", &c[i]);
  }

  std::sort(c.begin() + 1, c.end());

  std::vector<int> mini(n + 1, INF);
  mini[0] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
    }
  }

  std::printf("%d\n", mini[n]);
  return 0;
}