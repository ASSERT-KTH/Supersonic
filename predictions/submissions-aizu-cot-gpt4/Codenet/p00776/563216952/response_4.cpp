#include <iostream> // for cin, cout
#include <vector> // for vector
#include <algorithm> // for sort

#define rep(i, a, n) for (int i = a; i < n; i++)

void dfs(std::string& t, int now, std::vector<std::string>& vs) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  char orig = t[now];
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1, vs);
  }
  t[now] = orig;
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1, vs);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::string s;
  while (1) {
    std::cin >> s;
    if (s == "#")
      break;
    std::vector<std::string> vs;
    dfs(s, 0, vs);
    int ans = vs.size();
    if (ans > 10) {
      std::sort(vs.begin(), vs.end());
    }
    std::cout << ans << std::endl;
    if (ans <= 10) {
      rep(i, 0, ans) { std::cout << vs[i] << std::endl; }
    } else {
      rep(i, 0, 5) { std::cout << vs[i] << std::endl; }
      rep(i, ans - 5, ans) { std::cout << vs[i] << std::endl; }
    }
  }
  return 0;
}