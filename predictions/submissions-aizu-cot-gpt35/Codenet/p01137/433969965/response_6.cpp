#include <iostream>
#include <cmath>

const int inf = 1000000000;

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = e;
    int zmax = std::cbrt(e);
    for (int z = 0; z <= zmax; ++z) {
      int ymax = std::sqrt(e - z * z * z);
      for (int y = 0; y <= ymax; ++y) {
        int x = e - (y * y + z * z * z);
        ans = std::min(ans, x + y + z);
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}