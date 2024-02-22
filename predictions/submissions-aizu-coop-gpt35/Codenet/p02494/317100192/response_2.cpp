#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }

    // Error checking
    if (h <= 0 || w <= 0) {
      std::cout << "Invalid input. Height and width should be positive integers." << std::endl;
      continue;
    }

    // Create grid
    std::vector<std::vector<char>> grid(h, std::vector<char>(w, '#'));

    // Print grid
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        std::cout << grid[y][x];
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }
  return 0;
}