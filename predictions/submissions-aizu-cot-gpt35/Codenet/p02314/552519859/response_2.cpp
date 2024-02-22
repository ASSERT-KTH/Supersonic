#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 2000000000;

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> c;
  c.reserve(m);
  for (int i = 0; i < m; i++) {
    int coin;
    std::cin >> coin;
    c.push_back(coin);
  }

  std::sort(std::begin(c), std::end(c));

  std::vector<int> mini(n + 1, INF);
  mini[0] = 0;

  for (int i = 0; i < m; i++) {
    int diff = n - c[i];
    for (int j = c[i]; j <= n; j++) {
      mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
    }
  }

  std::cout << mini[n] << std::endl;

  return 0;
}