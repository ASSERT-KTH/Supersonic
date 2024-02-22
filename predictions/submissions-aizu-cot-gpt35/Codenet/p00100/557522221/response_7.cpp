#include <iostream>
#include <map>
#include <vector>

int main() {
  int n, i;
  while (std::cin >> n, n) {
    std::map<int, long long> m;
    std::vector<int> vec;
    vec.reserve(n); // Reserve memory space for vec
    long long p, q, value;
    bool found = false; // Flag variable to track if a value >= 1000000 is found
    while (n--) {
      std::cin >> i >> p >> q;
      auto it = m.emplace_hint(m.end(), i, p * q); // Insert or update element in m
      if (it->second >= 1000000 && !found) {
        found = true; // Set the flag if a value >= 1000000 is found
        std::cout << it->first << std::endl;
      }
    }
    if (!found)
      std::cout << "NA" << std::endl;
  }
}