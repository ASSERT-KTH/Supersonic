#include <iostream>

int main() {
  int H, W;
  while (true) {
    std::cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H - 2; i++) {
      for (int j = 1; j <= W - 2; j++) {
        if (i == 1 || i == H - 2 || j == 1 || j == W - 2) {
          std::cout << "#";
        } else {
          std::cout << ".";
        }
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
}