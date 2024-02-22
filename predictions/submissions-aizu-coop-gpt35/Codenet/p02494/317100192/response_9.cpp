#include <algorithm>
#include <iostream>
#include <cstring> // Include the cstring header for memset

auto main() -> int {
  int h, w;
  while (std::cin >> h >> w && !(h == 0 && w == 0)) { // Move the condition check to the loop condition
    char output[h * (w + 1)]; // Use a character array instead of a stringstream
    int pos = 0; // Track the current position in the output array
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        output[pos++] = '#'; // Append the character to the output array
      }
      output[pos++] = '\n'; // Append a newline character to the output array
    }
    output[pos] = '\0'; // Null-terminate the output array
    std::cout << output << std::endl; // Perform output operation outside the loop
  }
  return 0;
}