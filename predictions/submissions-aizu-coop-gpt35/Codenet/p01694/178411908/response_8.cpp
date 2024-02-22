#include <iostream>
#include <string>

int main() {
  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string now = "", next;
    for (int i = 0; i < n; ++i) {
      std::getline(std::cin, next);
      if (now == "lu" && next == "ru")
        ans++;
      else if (now == "ru" && next == "lu")
        ans++;
      else if (now == "ld" && next == "rd")
        ans++;
      else if (now == "rd" && next == "ld")
        ans++;
      now = next;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}