#include <iostream>

int main() {
  int a = 0, b = 0, H[100], W[100];

  while (a < 100 && std::cin >> H[a] >> W[a] && (H[a] != 0 || W[a] != 0)) {
    a++;
  }

  while (b < a) {
    for (int i = 0; i < H[b]; i++) {
      std::fill_n(std::ostreambuf_iterator<char>(std::cout), W[b], '#');
      std::cout << '\n';
    }
    b++;
    std::cout << '\n';
  }

  return 0;
}