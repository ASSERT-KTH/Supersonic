#include <algorithm>
#include <iostream>
#include <sstream>
auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    std::stringstream ss;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        ss << '#';
      }
      ss << '\n';
    }
    std::cout << ss.str() << std::endl;
  }
  return 0;
}
