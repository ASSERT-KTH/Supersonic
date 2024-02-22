#include <iostream>
#include <vector>

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<std::vector<uint32_t>> table;

public:
  StaticRMQ(std::vector<T>& array) : a(array), table(array.size()) {
    for (uint32_t i = 0; i < array.size(); ++i) {
      table[i].resize(32 - __builtin_clz(array.size() - i));
      table[i][0] = i;
    }
    for (uint32_t j = 1; (1 << j) <= array.size(); ++j) {
      for (uint32_t i = 0; i + (1 << j) <= array.size(); ++i) {
        table[i][j] = (array[table[i][j - 1]] < array[table[i + (1 << (j - 1))][j - 1]]) ? table[i][j - 1] : table[i + (1 << (j - 1))][j - 1];
      }
    }
  }

  uint32_t operator()(uint32_t begin, uint32_t end) {
    uint32_t k = 31 - __builtin_clz(end - begin + 1);
    return (a[table[begin][k]] < a[table[end - (1 << k) + 1][k]]) ? a[table[begin][k]] : a[table[end - (1 << k) + 1][k]];
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  uint32_t n, l;
  std::cin >> n >> l;

  std::vector<uint32_t> a(n);
  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  StaticRMQ<uint32_t> S(a);

  for (uint32_t i = 0; i <= n - l; ++i) {
    std::cout << S(i, i + l - 1) << " ";
  }

  std::cout << "\n";

  return 0;
}