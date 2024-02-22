#include <iostream>

int main() {
  int length;
  int width;
  std::ios_base::sync_with_stdio(false);
  std::cin >> length >> width;
  std::cout << length * width << ' ' << 2 * length + 2 * width << '\n';
}