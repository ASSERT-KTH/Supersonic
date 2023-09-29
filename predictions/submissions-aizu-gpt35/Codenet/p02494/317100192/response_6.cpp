#include <iostream>
#include <string>
auto main() -> int {
  int h, w;
  while (std::cin >> h >> w && h != 0 && w != 0) {
    std::string s(w, '#');
    for (int y = 0; y < h; ++y) {
      std::cout << s << '\n';
    }
    std::cout << std::endl;
  }
  return 0;
}