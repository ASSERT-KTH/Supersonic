#include <iostream>
#include <cmath>

int main(void) {
  int e;
  while (std::cin >> e, e) {
    int m = 1000000;
    int sqrt_e = std::sqrt(e);
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      for (int y = sqrt_e; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        m = (e - val2) + y + z < m ? (e - val2) + y + z : m;
      }
    }
    std::cout << m << std::endl;
  }
  return 0;
}