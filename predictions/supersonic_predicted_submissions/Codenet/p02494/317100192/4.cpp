#include <algorithm>
#include <iostream>
#include <sstream>
auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::stringstream ss;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        ss << '#';
      }
      ss << '\n';
    }
    std::cout << ss.str() << std::endl;
  }
  return 0;
}
