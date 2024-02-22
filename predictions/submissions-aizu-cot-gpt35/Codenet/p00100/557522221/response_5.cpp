#include <iostream>
#include <unordered_map>

int main() {
  int n, i;
  while (std::cin >> n, n) {
    std::unordered_map<int, long long> m;
    std::vector<int> vec;
    long long p, q;
    bool found = false;
    while (n--) {
      std::cin >> i >> p >> q;
      if (m.find(i) == m.end())
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i : vec) {
      if (m[i] >= 1000000) {
        found = true;
        std::cout << i << std::endl;
        break;
      }
    }
    if (!found)
      std::cout << "NA" << std::endl;
  }
}