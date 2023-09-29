#include <algorithm>
#include <iostream>
#include <sstream>
auto main() -> int {
  int h, w;
  std::stringstream ss;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    ss.str("");
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        ss << '#';
      }
      ss << '\n';
    }
    std::cout << ss.str();
  }
  return 0;
}