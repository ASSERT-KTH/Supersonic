#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int maxv, minv;
  std::cin >> minv >> maxv;

  for (int i = 2; i < n; i++) {
    int R;
    std::cin >> R;
    maxv = std::max(maxv, R - minv);
    minv = std::min(minv, R);
  }

  std::cout << maxv << std::endl;
  return 0;
}