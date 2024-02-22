#include <iostream>
#include <unordered_map>

int main() {
  int n, i;
  while (std::cin >> n, n) {
    std::unordered_map<int, long long> m;
    bool flag = false;

    while (n--) {
      std::cin >> i;
      long long p, q;
      std::cin >> p >> q;

      m[i] += p * q;

      if (m[i] >= 1000000 && !flag) {
        flag = true;
        std::cout << i << std::endl;
      }
    }

    if (!flag)
      std::cout << "NA" << std::endl;
  }
}