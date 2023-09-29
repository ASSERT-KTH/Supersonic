#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string now, next;
    for(int i = 0; i < n; ++i) {
      std::cin >> next;
      if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") || 
          (now == "ld" && next == "rd") || (now == "rd" && next == "ld"))
        ++ans;
      now.swap(next);
    }
    std::cout << ans << '\n';
  }
  return 0;
}