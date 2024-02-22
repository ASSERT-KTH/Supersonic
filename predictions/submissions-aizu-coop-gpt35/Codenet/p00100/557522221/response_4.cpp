#include <iostream>
#include <vector>
#include <utility>

int main() {
  int n, i;
  while (std::cin >> n, n) {
    std::vector<std::pair<int, long long>> vec;
    long long p, q;
    bool found = false;

    for (int j = 0; j < n; j++) {
      std::cin >> i >> p >> q;
      bool isNewKey = true;
      for (auto& pair : vec) {
        if (pair.first == i) {
          pair.second += p * q;
          isNewKey = false;
          break;
        }
      }
      if (isNewKey) {
        vec.push_back(std::make_pair(i, p * q));
      }
    }

    std::vector<int> resultKeys;
    for (const auto& pair : vec) {
      if (pair.second >= 1000000) {
        found = true;
        resultKeys.push_back(pair.first);
      }
    }

    if (found) {
      for (const auto& key : resultKeys) {
        std::cout << key << std::endl;
      }
    } else {
      std::cout << "NA" << std::endl;
    }
  }
  return 0;
}