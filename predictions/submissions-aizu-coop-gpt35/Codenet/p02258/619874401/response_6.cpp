#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int minv;
  std::cin >> minv;

  int maxv = 0;

  for (int i = 1; i < n; i++) {
    int num;
    std::cin >> num;

    if (num - minv > maxv) {
      maxv = num - minv;
    }

    if (num < minv) {
      minv = num;
    }
  }

  std::cout << maxv << std::endl;
  return 0;
}