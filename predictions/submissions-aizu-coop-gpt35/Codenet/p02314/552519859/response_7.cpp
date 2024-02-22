#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 2000000000;

int main() {
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> c(m);
  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
  }
  std::sort(c.begin(), c.end());

  std::vector<int> mini(n + 1, INF);
  mini[0] = 0;

  for (int i = 0; i < m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
    }
  }

  std::cout << mini[n] << std::endl;

  return 0;
}