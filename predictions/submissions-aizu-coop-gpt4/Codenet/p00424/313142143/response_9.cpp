#include <iostream>
#include <vector>

int main() {
  int n;
  while (std::cin >> n && n != 0) {
    std::vector<int> d(256, 0);
    std::vector<std::pair<char, char>> input(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> input[i].first >> input[i].second;
      d[input[i].first] = input[i].second - input[i].first;
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      char a;
      std::cin >> a;
      std::cout << static_cast<char>(a + d[a]);
    }
    std::cout << '\n';
  }
  return 0;
}