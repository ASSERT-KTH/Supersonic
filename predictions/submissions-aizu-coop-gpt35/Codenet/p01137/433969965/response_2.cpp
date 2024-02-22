#include <iostream>
#include <cmath>

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = 1000000000;
    for (int y = 0; y * y <= e; ++y) {
      int z = std::cbrt(e - y * y);
      int x = e - (y * y + z * z * z);
      ans = std::min(ans, x + y + z);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}