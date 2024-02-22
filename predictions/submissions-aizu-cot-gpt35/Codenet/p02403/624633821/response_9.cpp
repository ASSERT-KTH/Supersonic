#include <iostream>

const int MAX_SIZE = 100;

int main() {
  int numPairs = 0, H[MAX_SIZE], W[MAX_SIZE];

  while (true) {
    std::cin >> H[numPairs] >> W[numPairs];
    if (H[numPairs] == 0 && W[numPairs] == 0)
      break;
    numPairs++;
  }

  int pairIndex = 0;
  while (pairIndex < numPairs) {
    for (int i = 0; i < H[pairIndex]; i++) {
      for (int j = 0; j < W[pairIndex]; j++) {
        std::cout << "#";
      }
      std::cout << std::endl;
    }
    pairIndex++;
    std::cout << std::endl;
  }

  return 0;
}