#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<std::vector<uint32_t>> table;

public:
  StaticRMQ(std::vector<T>& array) {
    a = array;
    uint32_t n = array.size();
    uint32_t s = std::log2(n) + 1;
    table.resize(s, std::vector<uint32_t>(n));

    for (uint32_t i = 0; i < n; ++i) {
      table[0][i] = i;
    }

    for (uint32_t t = 1; t < s; ++t) {
      for (uint32_t i = 0; i < n; ++i) {
        if (i + (1 << (t - 1)) < n) {
          table[t][i] = (a[table[t - 1][i]] < a[table[t - 1][i + (1 << (t - 1))]])
                            ? table[t - 1][i]
                            : table[t - 1][i + (1 << (t - 1))];
        } else {
          table[t][i] = table[t - 1][i];
        }
      }
    }
  }

  uint32_t operator()(uint32_t begin, uint32_t end) {
    uint32_t t = std::log2(end - begin + 1);
    return std::min(a[table[t][begin]], a[table[t][end - (1 << t) + 1]]);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint32_t n, l;
  std::cin >> n >> l;

  std::vector<uint32_t> a(n);
  a.reserve(n);

  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  StaticRMQ<uint32_t> S(a);

  std::cout << S(0, l);

  for (uint32_t i = 1; i < n - l + 1; ++i) {
    std::cout << " " << S(i, i + l - 1);
  }

  std::cout << "\n";

  return 0;
}