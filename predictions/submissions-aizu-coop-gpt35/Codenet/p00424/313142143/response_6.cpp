#include <iostream>
#include <unordered_map>

int main() {
  int n;
  while (std::cin >> n && n) {
    std::unordered_map<char, int> d;
    char a, b;
    for (; n--; ) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    std::cin >> n;
    while (n--) {
      std::cin >> a;
      int result = a + d[a];
      putchar(result);
    }
    putchar('\n');
  }
  return 0;
}