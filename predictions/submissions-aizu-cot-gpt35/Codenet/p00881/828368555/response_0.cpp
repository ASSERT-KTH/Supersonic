#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <limits.h>

std::map<std::pair<std::vector<int>, int>, int> mp;
std::string qes[128];

int search(std::vector<int>& vi, int depth, int used, const int& m, const int& n) {
  if (mp.count({vi, used}))
    return mp[{vi, used}];
  if (vi.size() > (1 << (m - depth)))
    return INT_MAX;
  if (vi.size() == 1)
    return depth;
  int res = INT_MAX;
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
  return mp.emplace(std::pair<std::vector<int>, int>(vi, used), res).first->second;
}

int main() {
  int m, n;
  while (std::cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      std::cin >> qes[i];
    std::vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    mp.clear();
    std::cout << search(vi, 0, 0, m, n) << std::endl;
  }
}