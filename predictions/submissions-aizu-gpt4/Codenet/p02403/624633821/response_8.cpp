#include <iostream>
#define MAX 100

int main() {
  int a = 0, b = 0, H[MAX], W[MAX];
  while (std::cin >> H[a] >> W[a], H[a] || W[a]) a++;

  while (b < a) {
    std::cout << std::string(W[b], '#') << '\n';
    for (int i = 1; i < H[b]; i++) {
      std::cout << '#' << std::string(W[b] - 2, (W[b] > 1 ? ' ' : '#')) << '#' << '\n';
    }
    if(H[b] > 1) std::cout << std::string(W[b], '#') << '\n';
    std::cout << '\n';
    b++;
  }
  return 0;
}