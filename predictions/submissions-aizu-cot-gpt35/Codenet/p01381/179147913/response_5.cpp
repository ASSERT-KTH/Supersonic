#include <iostream>
#include <algorithm>

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    if (n / 2 < k) {
      std::cout << "-1" << std::endl;
      continue;
    }
    int p[n + 2];
    std::fill(p, p + n + 2, 0);
    for (int i = 0; i < n - 1; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        std::cout << std::endl;
      for (int j = 0; j < n - 1; j++) {
        int a = p[j] + i + 1;
        int b = p[j + 1] + i + 1;
        std::cout << a << " " << b << std::endl;
      }
    }
  }
}