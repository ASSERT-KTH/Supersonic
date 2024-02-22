#include <algorithm>
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
    rectangle.reserve(h * (w + 1)); // Pre-allocate memory for the rectangle

    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        rectangle.push_back('#'); // Append '#' character directly to the string
      }
      rectangle.push_back('\n'); // Append '\n' character directly to the string
    }
    std::cout << rectangle << std::endl; // Use endl to flush the output
  }
  return 0;
}