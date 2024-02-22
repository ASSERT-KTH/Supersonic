#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string prev, curr, next;
    std::unordered_map<std::string, int> strToId;

    for (int i = 0; i < n; ++i) {
      std::cin >> next;

      if (i > 0) {
        if (curr == "lu" && next == "ru") {
          ans++;
        } else if (curr == "ru" && next == "lu") {
          ans++;
        } else if (curr == "ld" && next == "rd") {
          ans++;
        } else if (curr == "rd" && next == "ld") {
          ans++;
        }
      }

      curr = next;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}