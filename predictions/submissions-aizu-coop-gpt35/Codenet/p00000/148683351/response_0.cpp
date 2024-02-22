#include <iostream>

int main() {
  for (int k = 1; k <= 81; k++) {
    int i = (k - 1) / 9 + 1;
    int j = (k - 1) % 9 + 1;
    std::cout << i << "x" << j << "=" << i * j << std::endl;
  }
  return 0;
}