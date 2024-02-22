#include <iostream>

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = e; // Initialize ans with e
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y + z * z * z <= e; ++y) {
        int x = e - (y * y + z * z * z);
        if (x >= 0 && x + y + z < ans) {
          ans = x + y + z;
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}