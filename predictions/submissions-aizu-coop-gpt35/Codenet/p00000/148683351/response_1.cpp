#include <iostream>

int main() {
  const int maxVal = 9;
  for (int i = 1; i <= maxVal; ++i) {
    for (int j = 1; j <= maxVal; ++j) {
      int result = i * j;
      std::cout << i << "x" << j << "=" << result << '\n';
    }
  }
  return 0;
}