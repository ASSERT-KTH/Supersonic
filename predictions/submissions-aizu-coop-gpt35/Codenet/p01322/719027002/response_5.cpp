#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::vector<int> o;
  std::vector<std::string> b;
  std::unordered_map<std::string, int> map;

  while (true) {
    std::cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    o.resize(n);
    b.resize(n);
    map.clear();

    for (int i = 0; i < n; i++)
      std::cin >> b[i] >> o[i];

    for (int i = 0; i < n; i++)
      map[b[i]] = o[i];

    int ans = 0;
    for (int i = 0; i < m; i++) {
      std::string l;
      std::cin >> l;
      auto it = map.find(l);
      if (it != map.end())
        ans += it->second;
    }

    std::cout << ans << '\n';
  }

  return 0;
}