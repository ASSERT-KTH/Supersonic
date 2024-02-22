#include <iostream>
#include <string>

auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }

    std::string rectangle;
    rectangle.reserve(h * w);

    for (int y = 0; y < h; ++y) {
      rectangle.clear();
      rectangle.resize(w, '#');
      std::cout << rectangle << '\n';
    }
  }
  return 0;
}