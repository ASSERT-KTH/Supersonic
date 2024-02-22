#include <iostream>
#include <string>

int main() {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string row(w, '#');
    row += '\n';
    for (int y = 0; y < h; ++y) {
      std::cout << row;
    }
    std::cout << std::endl;
  }
  return 0;
}