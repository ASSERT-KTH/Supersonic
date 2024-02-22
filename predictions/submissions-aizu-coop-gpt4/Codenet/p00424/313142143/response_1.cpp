#include <iostream>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  char a, b;
  while (std::cin >> n && n) {
    std::unordered_map<char, int> d;
    for (; n--; ) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    std::cin >> n;
    for (; n--; ) {
      a = std::cin.get();
      std::cout << char(a + d[a]);
    }
    std::cout << '\n';
  }
}