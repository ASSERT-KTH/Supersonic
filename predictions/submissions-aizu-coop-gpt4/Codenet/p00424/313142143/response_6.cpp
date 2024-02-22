#include <iostream>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  while (std::cin >> n && n) {
    std::unordered_map<char, int> d;
    for (char a, b; n--; ) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    std::cin >> n;
    while (n--) {
      char a = std::getchar();
      std::putchar(a + d[a]);
    }
    std::putchar('\n');
  }
}