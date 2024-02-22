#include <iostream>

int main() {
  int H, W;
  std::cin >> H >> W;

  while (H && W) {
    // Pre-calculate the lookup table
    char pattern[2] = {'.', '#'};
    char lookup[16];
    for (int i = 0; i < 16; i++) {
      lookup[i] = pattern[(i + 2) % 2];
    }

    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        std::cout << lookup[(i + j) % 16];
      }
      std::cout << '\n';
    }
    std::cout << '\n';

    std::cin >> H >> W;
  }

  return 0;
}