#include <iostream>
#include <string>

int main() {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string grid;
    grid.reserve(h * (w + 1));
    for (int y = 0; y < h; ++y) {
      grid.append(w, '#');
      grid += '\n';
    }
    std::cout << grid << '\n';
  }
  return 0;
}