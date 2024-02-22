#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string now = "", next;
    rep(i, n) {
      std::cin >> next;
      switch (next[0]) {
        case 'r':
          if ((now == "lu" && next == "ru") || (now == "ld" && next == "rd"))
            ans++;
          break;
        case 'l':
          if ((now == "ru" && next == "lu") || (now == "rd" && next == "ld"))
            ans++;
          break;
      }
      now = next;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}