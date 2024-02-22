#include <iostream>
#include <cmath>

int main() {
  int e;
  while (std::cin >> e, e) {
    int m = INT_MAX;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      for (int y = sqrt(e - val); (y * y) > (e - val); --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        if ((e - val2) + y + z < m)
          m = (e - val2) + y + z;
      }
    }
    std::cout << m << std::endl;
  }
  return EXIT_SUCCESS;
}