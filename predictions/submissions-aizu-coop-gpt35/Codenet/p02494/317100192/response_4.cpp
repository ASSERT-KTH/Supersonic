#include <iostream>
#include <string>

int main() {
  int h, w;
  while (true) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    std::string rectangle;
    rectangle.reserve(h * (w + 1)); // Reserve memory for the entire rectangle
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        rectangle.push_back('#'); // Append '#' character to the string
      }
      rectangle.push_back('\n'); // Append newline character to the string
    }
    std::cout << rectangle;
  }
  return 0;
}