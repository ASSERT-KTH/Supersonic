#include <iostream>
int main() {
  int H, W;
  std::cin >> H >> W;
  while (H * W != 0) {
    for (int k = 1; k <= H * W; k++) {
      int row = (k + H - 1) / H;
      int col = (k + H - 1) % H;
      std::cout << ".#"[(row + col) % 2 == 0];
      if (k % W == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cin >> H >> W;
  }
  return 0;
}