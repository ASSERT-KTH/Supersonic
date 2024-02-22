#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void dfs(std::string& t, int now, std::vector<std::string>& vs) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  for (int i = 0; i < now; i++) {
    d[t[i] - 'a']++;
  }
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now]++;
    dfs(t, now + 1, vs);
    t[now]--;
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
    dfs(t, now + 1, vs);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  while (std::cin >> s) {
    if (s == "#") {
      break;
    }
    std::vector<std::string> vs;
    dfs(s, 0, vs);
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