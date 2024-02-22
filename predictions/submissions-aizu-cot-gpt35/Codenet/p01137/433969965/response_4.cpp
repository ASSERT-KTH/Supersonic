#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = std::numeric_limits<int>::max();
    int maxZ = std::cbrt(e);
    for (int z = 0; z <= maxZ; ++z) {
      int maxY = std::sqrt(e - z * z * z);
      for (int y = 0; y <= maxY; ++y) {
        int sum = y + z + (e - y * y - z * z * z);
        ans = std::min(ans, sum);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}