#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define rep(i, a, n) for (int i = a; i < n; i++)

std::string s;
std::vector<std::string> vs;
std::bitset<26> f;

void dfs(std::string& t, int now) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  if (t[now] != 'z' && !f[t[now] - 'a' + 1]) {
    t[now]++;
    f[t[now] - 'a'] = true;
    dfs(t, now + 1);
    t[now]--;
    f[t[now] - 'a'] = false;
  }
  if (t[now] == 'a' || f[t[now] - 'a']) {
    dfs(t, now + 1);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  while (1) {
    std::cin >> s;
    if (s == "#")
      break;
    vs.clear();
    f.reset();
    dfs(s, 0);
    int ans = vs.size();
    std::cout << ans << std::endl;
    if (ans <= 10) {
      rep(i, 0, ans) { std::cout << vs[i] << std::endl; }
    } else {
      rep(i, 0, 5) { std::cout << vs[i] << std::endl; }
      rep(i, ans - 5, ans) { std::cout << vs[i] << std::endl; }
    }
  }
}