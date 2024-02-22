#include <iostream>

int main() {
  unsigned int H, W;
  std::cin >> H >> W;
  
  while (H != 0 && W != 0) {
    for (unsigned int i = 0; i < H; i++) {
      for (unsigned int j = 0; j < W; j++) {
        std::cout << ".#"[((i ^ j) & 1)];
      }
      std::cout << '\n';
    }
    std::cout << '\n';
    std::cin >> H >> W;
  }

  return 0;
}