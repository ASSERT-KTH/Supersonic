#include <iostream>
#include <cmath>
#include <algorithm>

int main(void) {
  int e;
  while (std::cin >> e, e) {
    int m = e;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      for (int y = std::sqrt(e - val); y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          break;
        m = std::min(m, (e - val2) + y + z);
      }
    }
    std::cout << m << std::endl;
  }
  return EXIT_SUCCESS;
}