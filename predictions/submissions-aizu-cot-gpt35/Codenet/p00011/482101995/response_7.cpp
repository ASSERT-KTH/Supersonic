#include <iostream>

int main() {
  int w;
  std::cin >> w;
  int n;
  std::cin >> n;

  for (int i = 0; i < w; i++) {
    std::cout << i + 1 << std::endl;
  }

  for (int i = 0; i < n; i++) {
    int left, right;
    char dummy;
    std::cin >> left >> dummy >> right;

    int temp = left;
    left = right;
    right = temp;
  }

  return 0;
}