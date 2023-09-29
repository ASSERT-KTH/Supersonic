#include <iostream>
#include <string>

int main() {
  int h, w;
  while (std::cin >> h >> w && h != 0 && w != 0) {
    std::string row(w, '#');
    for (int i = 0; i < h; ++i) {
      std::cout << row << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}