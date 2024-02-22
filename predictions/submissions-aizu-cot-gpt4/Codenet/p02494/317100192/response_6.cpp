#include <iostream>

int main() {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
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