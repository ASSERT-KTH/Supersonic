#include <array>
#include <iostream>

int main() {
  int a = 0;
  std::array<int, 100> H, W;
  
  while (true) {
    std::cin >> H[a] >> W[a];
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  
  for (int b = 0; b < a; b++) {
    for (int i = 0; i < H[b]; i++) {
      for (int j = 0; j < W[b]; j++) {
        std::cout << "#";
      }
      std::cout << "\n";
    }
    if (b < a - 1)
      std::cout << "\n";
  }
  
  return 0;
}