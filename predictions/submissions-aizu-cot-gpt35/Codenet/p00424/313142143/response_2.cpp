#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  while (std::cin >> n && n) {
    std::vector<int> d(256, 0);

    char a, b;
    while (n--) {
      std::cin >> a >> b;
      d[a] = b - a;
    }

    while (n--) {
      std::cin >> a;
      std::cout << (char)(a + d[a]);
    }

    std::cout << std::endl;
  }

  return 0;
}