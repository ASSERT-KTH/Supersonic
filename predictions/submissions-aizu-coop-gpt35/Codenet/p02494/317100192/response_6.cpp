#include <algorithm>
#include <iostream>

auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }

    std::string rectangle(h * w, '#'); // Step 1: Use a string to directly build the rectangle

    for (int y = 0; y < h; ++y) {
      // Step 2: Use std::fill algorithm to fill the string with a repeated character
      std::fill(rectangle.begin() + y * w, rectangle.begin() + (y + 1) * w, '#');
    }

    // Step 3: Use a single output operation to print the rectangle string
    std::cout << rectangle << '\n';
  }
  return 0;
}