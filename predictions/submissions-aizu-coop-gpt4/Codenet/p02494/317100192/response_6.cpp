#include <algorithm>
#include <iostream>
#include <string>

auto main() -> int {
  std::ios_base::sync_with_stdio(false);
  int h, w;
  std::string buffer;
  buffer.reserve(1000000); // Reserve large enough memory upfront
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string s(h * (w + 1), '#');
    for (int y = 0; y < h; ++y) {
      s[y * (w + 1) + w] = '\n';
    }
    buffer += s + "\n";
  }
  std::cout << buffer;
  return 0;
}