#include <iostream>
#include <string>
auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string row(w, '#');
    for (int y = 0; y < h; ++y) {
      std::cout << row << '\n';
    }
  }
  return 0;
}