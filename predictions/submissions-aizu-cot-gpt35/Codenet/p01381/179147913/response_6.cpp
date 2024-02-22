#include <iostream>

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    if (n / 2 < k) {
      std::cout << "-1\n";
      continue;
    }
    int p[n + 2];
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; ++i) {
      if (i != 0)
        std::cout << '\n';
      int a = (p[0] + i) % n + 1;
      for (int j = 0; j < n - 1; ++j) {
        int b = (p[j + 1] + i) % n + 1;
        std::cout << a << ' ' << b << '\n';
        a = b;
      }
    }
  }
}