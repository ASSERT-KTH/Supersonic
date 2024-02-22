#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> c(m);
  std::vector<int> mini(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
  }

  std::sort(c.begin(), c.end());

  mini[0] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = c[i - 1]; j <= n; j++) {
      mini[j] = std::min(mini[j], mini[j - c[i - 1]] + 1);
    }
  }

  std::cout << mini[n] << std::endl;

  return 0;
}