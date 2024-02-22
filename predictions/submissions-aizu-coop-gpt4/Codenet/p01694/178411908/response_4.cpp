#include <iostream>
#include <map>

enum State {
  LU,
  RU,
  LD,
  RD,
  INVALID
};

int main() {
  std::map<std::string, State> state_map = {
      {"lu", LU}, {"ru", RU}, {"ld", LD}, {"rd", RD}};
  bool transitions[4][4] = {{0, 1, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 1},
                            {0, 0, 1, 0}};
  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    State now = INVALID, next;
    std::string input;
    for (int i = 0; i < n; ++i) {
      std::cin >> input;
      next = state_map[input];
      if (now != INVALID && transitions[now][next]) {
        ans++;
      }
      now = next;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}