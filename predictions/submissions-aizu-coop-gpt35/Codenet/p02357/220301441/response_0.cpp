#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr uint32_t INF = 1000000000;
constexpr uint32_t MOD = 1000000007;
constexpr uint32_t bitmaskr[32] = {
    0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFC, 0xFFFFFFF8, 0xFFFFFFF0, 0xFFFFFFE0,
    0xFFFFFFC0, 0xFFFFFF80, 0xFFFFFF00, 0xFFFFFE00, 0xFFFFFC00, 0xFFFFF800,
    0xFFFFF000, 0xFFFFE000, 0xFFFFC000, 0xFFFF8000, 0xFFFF0000, 0xFFFE0000,
    0xFFFC0000, 0xFFF80000, 0xFFF00000, 0xFFE00000, 0xFFC00000, 0xFF800000,
    0xFF000000, 0xFE000000, 0xFC000000, 0xF8000000, 0xF0000000, 0xE0000000,
    0xC0000000, 0x80000000,
};
constexpr uint32_t bitmaskl[32] = {
    0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F,
    0x0000007F, 0x000000FF, 0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF,
    0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF, 0x0001FFFF, 0x0003FFFF,
    0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF,
    0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF,
    0x7FFFFFFF, 0xFFFFFFFF,
};

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<std::vector<uint32_t>> table;
  std::vector<uint32_t> R, L;

public:
  StaticRMQ(std::vector<T> &array) : a(array.size()), R((array.size() + 31) / 32), L((array.size() + 31) / 32) {
    uint32_t s = std::max((uint32_t)(31 ^ __builtin_clrsb(array.size() >> 5)), (uint32_t)1);
    table.resize(s + 1);
    table[0].resize((array.size() >> 5) + 1);
    for (uint32_t t = 0; t < array.size(); ++t) {
      a[t] = array[t];
      if (!(t & 0x1F)) {
        R[t >> 5] = 1;
        table[0][t >> 5] = t;
      }
      for (uint32_t c = t; c; --c) {
        if (!(array[t] < array[c - 1])) {
          break;
        }
        R[(t + 1) >> 5] |= 1 << ((t + 1) & 0x1F);
      }
      if (array[t] < a[table[0][t >> 5]]) {
        table[0][t >> 5] = t;
      }
      if (!((~t) & 0x1F)) {
        L[t >> 5] = R[t >> 5];
      }
    }
    for (uint32_t t = 1; t < s; ++t) {
      table[t].resize(table[t - 1].size() - (1 << (t - 1)) + 1);
      for (uint32_t m = 0; m < table[t].size(); ++m) {
        table[t][m] =
            a[table[t - 1][m]] < a[table[t - 1][m + (1 << (t - 1))]]
                ? table[t - 1][m]
                : table[t - 1][m + (1 << (t - 1))];
      }
    }
  }

  uint32_t operator()(uint32_t begin, uint32_t end) {
    uint32_t l = (begin >> 5) + 1;
    uint32_t r = --end >> 5;
    if (l < r) {
      uint32_t t = std::min(a[table[__builtin_clz(r - l + 1)][l]],
                            a[table[__builtin_clz(r - l + 1)][r - (1 << __builtin_clz(r - l + 1)) + 1]]);
      t = std::min(
          a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])],
          t);
      return std::min(
          a[(end & ~0x1F) | (__builtin_clz(R[end >> 5]) ^ 31) & bitmaskl[end & 0x1F]],
          t);
    }
    if (l == r) {
      uint32_t t = a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])];
      return std::min(
          a[(end & ~0x1F) | (__builtin_clz(R[end >> 5]) ^ 31) & bitmaskl[end & 0x1F]],
          t);
    }
    return a[(end & ~0x1F) | __builtin_ctz(R[end >> 5] & bitmaskr[begin & 0x1F])];
  }
};

int main(void) {