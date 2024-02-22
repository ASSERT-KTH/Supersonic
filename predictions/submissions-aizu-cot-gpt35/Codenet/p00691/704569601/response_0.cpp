#include <iostream>

int main() {
  long long z;
  while (std::cin >> z && z) {
    long long ans = 0;
    for (long long x = 1; x * x * x <= z; x++) {
      long long max_y = cbrt(z * z * z - x * x * x) + 1;
      for (long long y = 1; y * y * y <= z * z * z - x * x * x && y <= max_y; y++) {
        ans = std::max(ans, x * x * x + y * y * y);
      }
    }
    std::cout << z * z * z - ans << std::endl;
  }
}