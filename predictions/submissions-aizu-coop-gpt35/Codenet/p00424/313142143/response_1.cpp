#include <iostream>
#include <unordered_map>

int main() {
  int n;
  while (std::cin >> n && n) {
    std::unordered_map<char, int> differences;
    char a, b;

    for (int i = 0; i < n; i++) {
      std::cin >> a >> b;
      differences[a] = b - a;
    }

    while (n--) {
      std::cin >> a;
      std::cout << static_cast<char>(a + differences[a]);
    }
    std::cout << std::endl;
  }
}