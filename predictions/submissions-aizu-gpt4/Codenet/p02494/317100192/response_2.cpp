#include <iostream>
#include <string>

auto main() -> int {
  int h, w;
  while (std::cin >> h >> w && h != 0 && w != 0) {
    std::cout << std::string(w, '#') << '\n';
    for(int y = 1; y < h; ++y){
        std::cout << std::string(w, '#') << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}