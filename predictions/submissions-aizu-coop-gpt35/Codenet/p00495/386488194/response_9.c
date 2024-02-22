#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }

  int m = 0;
  std::vector<int> d(n + 1, 0);

  int x;
  while (std::cin >> x) {
    for (int i = n; i >= 1; --i) {
      d[i] = x == c[i - 1] ? d[i - 1] + 1 : std::max(d[i], d[i - 1]);
      m = std::max(m, d[i]);
    }
  }

  std::cout << m << std::endl;

  return 0;
}