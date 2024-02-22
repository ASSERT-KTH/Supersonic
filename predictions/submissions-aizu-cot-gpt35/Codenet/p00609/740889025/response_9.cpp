#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<std::vector<int>> v;
  int aN, bN, R;
  while (std::cin >> aN >> bN >> R && aN) {
    v.clear();
    v.resize(10000);
    for (int i = 0; i < aN; i++) {
      int x, y;
      std::cin >> x >> y;
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      std::sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      std::cin >> x >> y;
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = std::sqrt((D - p) * (D + p));
        ans += std::upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               std::lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    std::cout << ans << std::endl;
  }
}