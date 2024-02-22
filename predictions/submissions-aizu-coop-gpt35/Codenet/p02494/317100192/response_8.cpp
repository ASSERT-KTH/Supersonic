#include <iostream>

auto main() -> int {
  int h, w;
  std::cin >> h >> w;
  
  while (h != 0 && w != 0) {
    std::string row(w, '#');
    for (int y = 0; y < h; ++y) {
      std::cout << row << std::endl;
    }
    std::cin >> h >> w;
  }
  
  return 0;
}