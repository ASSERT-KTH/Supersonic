#include <iostream>
#include <string>

auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string rectangle(h * (w + 1), '#');  // preallocate memory for the entire rectangle
    for (int y = 0; y < h; ++y) {
      rectangle[y * (w + 1) + w] = '\n';  // replace the last '#' in each row with '\n'
    }
    std::cout << rectangle << '\n';  // replace std::endl with '\n'
  }
  return 0;
}