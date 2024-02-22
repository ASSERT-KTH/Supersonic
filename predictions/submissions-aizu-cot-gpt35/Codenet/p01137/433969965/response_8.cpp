#include <iostream>
#include <cmath>

const int inf = 1000000000;

int main() {
  unsigned int e;
  while (std::cin >> e, e) {
    int ans = inf;
    for (unsigned int z = 0; z <= cbrt(e); ++z) {
      for (unsigned int y = 0; y <= sqrt(e - z * z * z); ++y) {
        unsigned int x = e - (y * y + z * z * z);
        ans = std::min(ans, static_cast<int>(x + y + z));
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}