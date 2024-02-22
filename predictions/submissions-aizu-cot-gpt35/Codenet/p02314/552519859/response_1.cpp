#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 2000000000;

int main() {
  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> c(m + 1);
  for (int i = 1; i <= m; ++i) {
    std::cin >> c[i];
  }
  
  std::sort(c.begin() + 1, c.end());
  
  std::vector<int> mini(n + 1, INF);
  mini[0] = 0;

  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n - c[i]; ++j) {
      mini[j + c[i]] = std::min(mini[j] + 1, mini[j + c[i]]);
    }
  }
  
  std::cout << mini[n] << std::endl;
  return 0;
}