#include <iostream>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  while (std::cin >> n && n != 0) {
    std::unordered_map<char, int> d;
    char a, b;
    for (; n--; ) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    for (; n--; ) {
      std::cin >> a;
      std::cout.put(a + d[a]);
    }
    std::cout << std::endl;
  }

  return 0;
}