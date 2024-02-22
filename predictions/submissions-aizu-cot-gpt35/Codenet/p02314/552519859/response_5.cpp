#include <iostream>
#include <vector>
#include <limits>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> c(m);
  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
  }
  std::vector<int> mini(n + 1, std::numeric_limits<int>::max());
  mini[0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
    }
  }
  std::cout << mini[n] << std::endl;
  return 0;
}