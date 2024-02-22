#include <iostream>

auto main() -> int {
  int h, w;
  while (std::cin >> h >> w && !(h == 0 && w == 0)) {
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        std::cout << '#';
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }
  return 0;
}