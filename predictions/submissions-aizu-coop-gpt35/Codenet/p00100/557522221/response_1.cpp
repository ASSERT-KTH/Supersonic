#include <iostream>
#include <unordered_map>
#include <set>

int main() {
  int n, i;
  while (std::cin >> n && n != 0) {
    std::unordered_map<int, long long> m;
    std::set<int> keys;
    bool found = false;

    while (n--) {
      std::cin >> i;
      long long p, q;
      std::cin >> p >> q;

      if (!m.count(i))
        keys.insert(i);
      m[i] += p * q;
    }

    for (auto it = keys.begin(); it != keys.end(); ++it) {
      if (m[*it] >= 1000000) {
        found = true;
        std::cout << *it << std::endl;
      }
    }

    if (!found)
      std::cout << "NA" << std::endl;
  }
  return 0;
}