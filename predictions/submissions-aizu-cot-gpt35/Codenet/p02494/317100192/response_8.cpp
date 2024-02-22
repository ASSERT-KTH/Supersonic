#include <iostream>

int main() {
  int h, w;
  while (true) {
    std::cin >> h >> w;
    if (!(h || w)) {
      break;
    }
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        std::cout << '#';
      }
      std::cout << '\n';
    }
  }
  return 0;
}