#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> v[10000];

int main() {
  int aN, bN, R;
  while (std::cin >> aN >> bN >> R && aN) {
    for (int i = 0; i < aN; i++) {
      int x, y;
      std::cin >> x >> y;
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      std::sort(v[i].begin(), v[i].end());

    const int D = 4 * R;
    const int DD = D * D;
    int ans = 0;

    for (int i = 0; i < bN; i++) {
      int x, y;
      std::cin >> x >> y;
      int m = std::sqrt(DD - y * y);

      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;

        ans += std::upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               std::lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    std::cout << ans << std::endl;
  }
}