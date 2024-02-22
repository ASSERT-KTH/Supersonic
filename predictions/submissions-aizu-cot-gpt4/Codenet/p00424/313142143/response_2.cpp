#include <iostream>
int main() {
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  
  int n;
  for (char a, b; std::cin >> n, n; std::cout << "\n") {
    int d[256] = {};
    for (; n--; d[a] = b - a)
      std::cin >> a >> b;
    for (std::cin >> n; n--; std::cout << static_cast<char>(a + d[a]))
      std::cin >> a;
  }
}