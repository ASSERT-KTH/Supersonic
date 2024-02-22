#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::string>& vs, const std::string& s, std::string t, int now) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  if (t[now] != 'z' && t[now] + 1 != 'a' && t.find(t[now] + 1, 0, now) == std::string::npos) {
    t[now] = t[now] + 1;
    dfs(vs, s, t, now + 1);
  }
  dfs(vs, s, t, now + 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::string s;
  while (true) {
    std::cin >> s;
    if (s == "#")
      break;
    std::vector<std::string> vs;
    dfs(vs, s, s, 0);
    int ans = vs.size();
    std::cout << ans << std::endl;
    if (ans <= 10) {
      for (int i = 0; i < ans; i++) {
        std::cout << vs[i] << std::endl;
      }
    } else {
      for (int i = 0; i < 5; i++) {
        std::cout << vs[i] << std::endl;
      }
      for (int i = ans - 5; i < ans; i++) {
        std::cout << vs[i] << std::endl;
      }
    }
  }
  return 0;
}