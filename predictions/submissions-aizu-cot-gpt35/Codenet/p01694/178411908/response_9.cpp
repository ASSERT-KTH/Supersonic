#include <iostream>
#include <string_view>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string_view now = "", next;
    std::unordered_map<std::string_view, int> combinations = {
        {"luru", 1}, {"rulu", 1}, {"ldrd", 1}, {"rdld", 1}};
    for (int i = 0; i < n; ++i) {
      std::cin >> next;
      ans += combinations[now + next];
      now = next[1];
    }
    std::cout << ans << '\n';
  }
  return 0;
}