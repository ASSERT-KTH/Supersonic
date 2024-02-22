#include <algorithm>
#include <iostream>
#include <vector>

typedef std::pair<int, int> pii;

int main() {
  int aN, bN, R;
  while (std::scanf("%d%d%d", &aN, &bN, &R), aN) {
    std::vector<std::vector<int>> v(aN);
    for (int i = 0; i < aN; i++) {
      int x, y;
      std::scanf("%d%d", &x, &y);
      v[y].emplace_back(x);
    }
    for (auto& vec : v) {
      std::sort(vec.begin(), vec.end());
    }
    int D = 4 * R;
    int ans = 0;
    std::vector<int> output;
    output.reserve(bN);
    for (int i = 0; i < bN; i++) {
      int x, y;
      std::scanf("%d%d", &x, &y);
      int dSquared = D * D;
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= aN)
          continue;
        int m = std::sqrt(dSquared - p * p);
        ans += std::upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               std::lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}