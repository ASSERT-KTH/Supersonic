#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, i;
  while (std::cin >> n, n) {
    std::unordered_map<int, long long> m;
    std::vector<int> vec;
    long long p, q, s = 0;
    vec.reserve(n);
    while (n--) {
      std::cin >> i >> p >> q;
      if (!m.count(i))
        vec.push_back(i);
      m[i] += p * q;
    }
    for (const auto &i : vec) {
      if (m[i] >= 1000000) {
        s = 1;
        std::cout << i << '\n';
      }
    }
    if (!s)
      std::cout << "NA" << '\n';
  }
}