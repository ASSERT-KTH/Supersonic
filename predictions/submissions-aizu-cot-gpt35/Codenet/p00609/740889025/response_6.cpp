#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> v(10000);

  int aN, bN, R;
  while (std::cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < aN; i++) {
      int x, y;
      std::cin >> x >> y;
      v[y].push_back(x);
    }

    for (auto& vec : v) {
      std::sort(vec.begin(), vec.end());
    }

    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      std::cin >> x >> y;
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000) {
          continue;
        }
        int m = (D - p) * (D + p);
        ans += std::upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               std::lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    std::cout << ans << std::endl;
  }
}