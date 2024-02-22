#include <iostream>
#include <cmath>

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = e;
    for (int z = 0; z <= std::cbrt(e); ++z) {
      int zz = z * z * z;
      for (int y = 0; y <= std::sqrt(e - zz); ++y) {
        int yy = y * y;
        int x = e - (yy + zz);
        ans = std::min(ans, x + y + z);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}