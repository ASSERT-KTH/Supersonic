#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::vector<int> o;
  std::vector<std::string> b;
  std::string l;
  int ans;

  for (;;) {
    std::cin >> n >> m;

    if (n == 0 && m == 0)
      break;

    o.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++)
      std::cin >> b[i] >> o[i];

    std::unordered_map<std::string, int> map;
    for (int i = 0; i < n; i++)
      map[b[i]] = o[i];

    ans = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> l;
      auto it = map.find(l);
      if (it != map.end())
        ans += it->second;
    }

    std::cout << ans << '\n';
  }

  return 0;
}