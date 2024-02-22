#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    if (n / 2 < k) {
      printf("-1\n");
      continue;
    }
    std::vector<int> p(n);
    p[0] = 0;
    for (int i = 0; i < n - 2; i += 4) {
      int p1 = i / 2 + 1;
      int p2 = n - p1;
      int a = (p1 + k - 1) % n + 1;
      int b = (p2 + k - 1) % n + 1;
      printf("%d %d\n", a, b);
      a = (p2 + k - 1) % n + 1;
      b = (p1 + 1 + k - 1) % n + 1;
      printf("%d %d\n", a, b);
      a = (p1 + 1 + k - 1) % n + 1;
      b = (p2 + 1 + k - 1) % n + 1;
      printf("%d %d\n", a, b);
      a = (p2 + 1 + k - 1) % n + 1;
      b = (p1 + 2 + k - 1) % n + 1;
      printf("%d %d\n", a, b);
    }
  }
}