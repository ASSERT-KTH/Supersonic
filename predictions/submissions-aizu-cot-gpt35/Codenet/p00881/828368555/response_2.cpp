#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::string> qes(128);
std::unordered_map<std::pair<std::vector<int>, int>, int> mp;

int search(std::vector<int>& vi, int depth, int used, int m, int n) {
  auto key = std::make_pair(vi, used);
  if (mp.count(key))
    return mp[key];
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    std::vector<int> a, b;
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = std::min(res, std::max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp.emplace_hint(mp.end(), key, res)->second;
}

int main() {
  int m, n;
  while (std::cin >> m >> n, m) {
    qes.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> qes[i];
    std::vector<int> vi;
    vi.reserve(n);
    for (int i = 0; i < n; i++)
      vi.push_back(i);
    mp.clear();
    std::cout << search(vi, 0, 0, m, n) << std::endl;
  }
}