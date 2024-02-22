#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 1000000000;

int main() {
  int e;
  while (std::cin >> e && e) {
    int ans = inf;
    int z_max = std::cbrt(e); // Maximum value of z
    for (int z = 0; z <= z_max; ++z) {
      int y_max = std::sqrt(e - z * z * z); // Maximum value of y
      for (int y = 0; y <= y_max; ++y) {
        int x = e - (y * y + z * z * z);
        ans = std::min(ans, x + y + z);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}