#include <iostream>
#include <string>

auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string str;
    str.reserve(h * (w + 1));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        str += '#';
      }
      str += '\n';
    }
    std::cout << str << '\n';
  }
  return 0;
}