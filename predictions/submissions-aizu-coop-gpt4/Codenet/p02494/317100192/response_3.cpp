#include <iostream>
#include <string>

int main() {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string row(w, '#');  // create a string of '#' characters
    for (int y = 0; y < h; ++y) {
      std::cout << row << '\n';  // directly output the string
    }
    std::cout << std::endl;
  }
  return 0;
}