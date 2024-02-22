#include <iostream>
#include <cmath>

int main(void) {
  int e;
  while (scanf("%d", &e), e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int sqrt_e_val = int(sqrt(e - val));
      for (int y = sqrt_e_val; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        m = std::min(m, (e - val2) + y + z);
      }
    }
    printf("%d\n", m);
  }
  return EXIT_SUCCESS;
}