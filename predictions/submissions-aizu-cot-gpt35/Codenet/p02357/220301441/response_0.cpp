#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<std::vector<uint32_t>> table;
  std::vector<uint32_t> R, L, part;

public:
  StaticRMQ(std::vector<T>& array) {
    a = array;
    uint32_t size = array.size();
    uint32_t s = std::max(static_cast<uint32_t>(31 ^ __builtin_clrsb(size >> 5)), static_cast<uint32_t>(1));
    table.resize(s + 1);
    table[0].resize((size >> 5) + 1);
    R.resize((size + 0x1F) >> 5);
    L.resize((size + 0x1F) >> 5);
    part.resize(size);

    for (uint32_t t = 0; t < size; ++t) {
      part[t] = 1 << (t & 0x1F);
      if (!(t & 0x1F)) {
        R[t >> 5] = 1;
        table[0][t >> 5] = t;
      }
      for (uint32_t c = 0; c < t; ++c) {
        if (!(array[t] < array[c])) {
          part[t] |= part[c];
          break;
        }
      }
      if (array[t] < array[table[0][t >> 5]]) {
        R[t >> 5] |= 1 << (t & 0x1F);
        table[0][t >> 5] = t;
      }
      if (!((~t) & 0x1F)) {
        L[t >> 5] = part[t];
      }
    }

    for (uint32_t t = 0; t < s; ++t) {
      table[t + 1].resize(table[t].size() - (1 << t) + 1);
      for (uint32_t m = 0; m < table[t + 1].size(); ++m) {
        table[t + 1][m] = a[table[t][m]] < a[table[t][m + (1 << t)]]
                              ? table[t][m]
                              : table[t][m + (1 << t)];
      }
    }
  }

  uint32_t operator()(uint32_t begin, uint32_t end) {
    uint32_t l = (begin >> 5) + 1;
    uint32_t r = --end >> 5;
    if (l < r) {
      uint32_t t = 31 ^ __builtin_clz(r - l);
      t = std::min(a[table[t][l]], a[table[t][r - (1 << t)]]);
      t = std::min(a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & ((1 << (begin & 0x1F)) - 1))], t);
      return std::min(a[(end & ~0x1F) | (31 ^ __builtin_clz(R[end >> 5] & ((1 << (end & 0x1F)) - 1)))], t);
    }
    if (l == r) {
      uint32_t t = a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & ((1 << (begin & 0x1F)) - 1))];
      return std::min(a[(end & ~0x1F) | (31 ^ __builtin_clz(R[end >> 5] & ((1 << (end & 0x1F)) - 1)))], t);
    }
    return a[(end & ~0x1F) | __builtin_ctz(part[end] & ((1 << (begin & 0x1F)) - 1))];
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