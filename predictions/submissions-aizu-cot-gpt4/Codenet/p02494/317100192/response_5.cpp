#include <iostream>

int main() {
  int h, w;
  while (true) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        std::cout << '#';
      }
      if (y != h - 1) std::cout << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}