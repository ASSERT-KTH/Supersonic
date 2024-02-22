#include <iostream>
#include <vector>

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<std::vector<uint32_t>> table;

public:
  StaticRMQ(std::vector<T>& array) {
    uint32_t n = array.size();
    a = array;
    table.resize(n, std::vector<uint32_t>(n));

    for (uint32_t i = 0; i < n; ++i) {
      table[i][i] = i;
      for (uint32_t j = i + 1; j < n; ++j) {
        table[i][j] = (a[table[i][j - 1]] < a[j]) ? table[i][j - 1] : j;
      }
    }
  }

  uint32_t operator()(uint32_t begin, uint32_t end) {
    return a[std::min_element(table[begin].begin() + begin, table[begin].begin() + end + 1) - table[begin].begin()];
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  uint32_t n, l;
  std::cin >> n >> l;

  std::vector<uint32_t> a(n);
  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  StaticRMQ<uint32_t> S(a);
  std::cout << S(0, l);

  for (uint32_t i = 1; i < n - l + 1; ++i) {
    std::cout << " " << S(i, i + l);
  }

  std::cout << "\n";
  return 0;
}