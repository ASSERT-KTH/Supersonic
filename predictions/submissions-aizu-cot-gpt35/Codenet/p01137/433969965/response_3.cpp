#include <iostream>

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = 1000000000;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y <= e - z * z * z; ++y) {
        int x = e - (y * y + z * z * z);
        ans = std::min(ans, x + y + z);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}