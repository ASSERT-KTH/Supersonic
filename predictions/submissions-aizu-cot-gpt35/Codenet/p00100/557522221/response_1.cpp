#include <iostream>
#include <map>
#include <vector>

int main() {
  int n, i;
  std::map<int, long long> m;
  std::vector<int> vec;
  while (std::cin >> n, n) {
    m.clear();
    vec.clear();
    long long p, q;
    bool found = false;
    while (n--) {
      std::cin >> i >> p >> q;
      if (m.count(i) == 0)
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i = 0; i < vec.size(); i++) {
      if (m.at(vec[i]) >= 1000000) {
        found = true;
        std::cout << vec[i] << std::endl;
      }
    }
    if (!found)
      std::cout << "NA" << std::endl;
  }
}