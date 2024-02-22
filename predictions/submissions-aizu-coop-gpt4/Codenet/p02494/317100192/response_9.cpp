#include <iostream>
#include <string>

int main() {
  int h, w;
  for (;;) {
    std::cin >> h >> w;
    if (h == 0 && w == 0) {
      break;
    }
    // Create a string filled with '#' of length 'w'
    std::string row(w, '#');
    // Append the newline character
    row += '\n';
    // Create the rectangle string and reserve its size in advance
    std::string rectangle;
    rectangle.reserve(h * (w + 1));
    for (int y = 0; y < h; ++y) {
      // Append the row string to the rectangle string
      rectangle += row;
    }
    std::cout << rectangle << std::endl;
  }
  return 0;
}