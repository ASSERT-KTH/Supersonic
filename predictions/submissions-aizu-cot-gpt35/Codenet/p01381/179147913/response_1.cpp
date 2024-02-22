#include <iostream>

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    int half_n = n / 2;
    if (half_n < k) {
      std::cout << "-1\n";
      continue;
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        std::cout << "\n";
      for (int j = 0; j < n - 1; j++) {
        int a = (j / 2 + 1 + i) % n + 1;
        int b = (n - a + i) % n + 1;
        std::cout << a << " " << b << "\n";
      }
    }
  }
}