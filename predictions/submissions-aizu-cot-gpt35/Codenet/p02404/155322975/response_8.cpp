#include <iostream>

int main() {
  int H, W;
  while (true) {
    std::cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; ++i) {
      for (int j = 1; j <= W; ++j) {
        if (i == 1 || i == H || j == 1 || j == W) {
          std::cout << "#";
        } else {
          std::cout << ".";
        }
      }
      std::cout << '\n';
    }
    if (H != 0 && W != 0)
      std::cout << '\n';
  }
}