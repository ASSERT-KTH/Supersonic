#include <iostream>
#include <string>

int main() {
  int h, w;
  while (true) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string line(w, '#');
    for (int y = 0; y < h; ++y) {
      std::cout << line << '\n';
    }
    std::cout << std::endl;
  }
  return 0;
}