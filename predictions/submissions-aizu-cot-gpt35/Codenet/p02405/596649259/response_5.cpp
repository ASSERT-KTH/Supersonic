#include <iostream>

int main() {
  int H, W;
  while (std::cin >> H >> W && H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if ((i + j) % 2 == 0) {
          std::cout << '.';
        } else {
          std::cout << '#';
        }
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}