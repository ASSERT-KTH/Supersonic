#include <iostream>
#include <vector>
#include <cmath>

const int inf = 1000000000;

int main() {
  int e;
  while (std::cin >> e, e) {
    int ans = inf;
    int sqrt_e;
    for (int z = 0; (z * z * z <= e) && (ans > 0); ++z) {
      sqrt_e = std::sqrt(e - z * z * z);
      for (int y = 0; (y * y <= e - z * z * z) && (ans > 0); ++y) {
        int x = e - (y * y + z * z * z);
        if (x + y + z < ans) {
          ans = x + y + z;
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}