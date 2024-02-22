#include <iostream>

int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int result = i * j;
      std::cout << i << "x" << j << "=" << result << '\n';
    }
  }
  return 0;
}