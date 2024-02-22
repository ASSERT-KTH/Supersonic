#include <iostream>
#include <cmath>
#include <algorithm>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  
  int e;
  while (std::cin >> e, e) {
    int min_m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = std::pow(z, 3);
      if (val > e)
        continue;
      
      int sqrt_e_minus_val = static_cast<int>(std::sqrt(e - val));
      for (int y = sqrt_e_minus_val; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        
        min_m = std::min(min_m, (e - val2) + y + z);
      }
    }
    std::cout << min_m << '\n';
  }
  
  return EXIT_SUCCESS;
}