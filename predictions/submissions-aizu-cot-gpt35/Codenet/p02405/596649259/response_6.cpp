#include <iostream>

int main() {
  int H, W;
  std::cin >> H >> W;

  while (H != 0 && W != 0) {
    for (int k = 1; k <= H * W; k++) {
      int i = (k - 1) / W + 1;
      int j = (k - 1) % W + 1;
      
      std::cout << (k % 2 == 0 ? '#' : '.') << (j == W ? '\n' : '');
    }
    
    std::cout << '\n';
    std::cin >> H >> W;
  }

  return 0;
}