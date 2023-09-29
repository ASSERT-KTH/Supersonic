#include <iostream>

int main() {
  int n, k, nonZeroCount, pairCount;

  while (std::cin >> n && n != 0) {
    nonZeroCount = pairCount = n;

    for (int i = 0; i < n; i++) {
      std::cin >> k;

      if (k == 0) {
        --nonZeroCount;
      } else if (k >= 2) {
        std::cout << nonZeroCount + 1 << '\n';
        pairCount = -1;
        break;
      }
    }

    if (pairCount != -1) {
      std::cout << "NA\n";
    }
  }

  return 0;
}