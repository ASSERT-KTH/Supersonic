#include <iostream>

int main() {
  for (int i = 1, j = 1; i <= 9; ++j) {
    std::cout << i << "x" << j << "=" << i * j << '\n';

    if (j == 9) {
      ++i;
      j = 0;
    }
  }

  return 0;
}