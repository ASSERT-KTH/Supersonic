#include <iostream>

int main() {
  int H, W;
  while (true) {
    std::cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        char ch;
        if (i == 1 || i == H || j == 1 || j == W) {
          ch = '#';
        } else {
          ch = '.';
        }
        std::cout << ch;
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
}