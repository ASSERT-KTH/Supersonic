#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::string>& vs, std::string& t, int now) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  std::vector<int> d(26, 0);
  for (int i = 0; i < now; i++) {
    d[t[i] - 'a']++;
  }
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now]++;
    dfs(vs, t, now + 1);
    t[now]--;
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
    dfs(vs, t, now + 1);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  while (std::cin >> s && s != "#") {
    std::vector<std::string> vs;
    dfs(vs, s, 0);
    int ans = vs.size();

    std::partial_sort(vs.begin(), vs.begin() + 10, vs.end());

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