#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i, a, b) for (uint32 i = (a); i < (b); ++i)
#define bitget(a, b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(), (x).end()

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

template <typename T>
class StaticRMQ {
  std::vector<T> a;
  std::vector<uint32> table, R, L, part;
  uint32 bitmaskr[32], bitmaskl[32];
  uint32 t;

public:
  StaticRMQ(std::vector<T>& array) {
    uint32 s, m, c = 0, e[32] = {};

    a.resize(array.size());
    R.resize((array.size() + 0x1F) >> 5);
    L.resize((array.size() + 0x1F) >> 5);
    part.resize(array.size());

    s = std::max((uint32)(31 ^ __builtin_clrsb(array.size() >> 5)), (uint32)1);
    table.resize(s + 1);

    e[1] = (array.size() >> 5) + 1;
    t = 0;
    while ((1 << ++t) < (array.size() >> 5))
      e[t + 1] = e[t] + (array.size() >> 5) - (1 << t) + 1;

    table[0] = e[t];
    for (t = 1; e[t]; ++t)
      table[t] = table[0] + e[t];

    for (t = 0; t < array.size(); ++t) {
      a[t] = array[t];
      part[t] = 1 << (t & 0x1F);
      if (!(t & 0x1F)) {
        m = array[t];
        R[t >> 5] = 1;
        table[0][t >> 5] = t;
        c = 0;
      }

      while (c)
        if (!(array[t] < array[e[--c]])) {
          part[t] |= part[e[c++]];
          break;
        }
      e[c++] = t;

      if (array[t] < m) {
        m = array[t];
        R[t >> 5] |= 1 << (t & 0x1F);
        table[0][t >> 5] = t;
      }
      if (!((~t) & 0x1F)) {
        L[t >> 5] = part[t];
      }
    }

    --s;
    for (t = 0; t < s; ++t) {
      for (m = 0; m < (uint32)(table[t + 2] - table[t + 1]); ++m) {
        table[t + 1][m] = a[table[t][m]] < a[table[t][m + (1 << t)]]
                              ? table[t][m]
                              : table[t][m + (1 << t)];
      }
    }
  }

  uint32 operator()(uint32 begin, uint32 end) {
    uint32 l = (begin >> 5) + 1;
    uint32 r = --end >> 5;
    if (l < r) {
      t = 31 ^ __builtin_clz(r - l);
      t = std::min(a[table[t][l]], a[table[t][r - (1 << t)]]);
      t = std::min(a[(begin & ~0x1F) |
                     __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])],
                   t);
      return std::min(
          a[(end & ~0x1F) |
            (31 ^ __builtin_clz(R[end >> 5] & bitmaskl[end & 0x1F]))],
          t);
    }
    if (l == r) {
      t = a[(begin & ~0x1F) |
            __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])];
      return std::min(
          a[(end & ~0x1F) |
            (31 ^ __builtin_clz(R[end >> 5] & bitmaskl[end & 0x1F]))],
          t);
    }
    return a[(end & ~0x1F) | __builtin_ctz(part[end] & bitmaskr[begin & 0x1F])];
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, l;
  std::cin >> n >> l;
  std::vector<uint32> a(n);
  rep(i, 0, n) { std::cin >> a[i]; }
  StaticRMQ<uint32> S(a);
  std::cout << S(0, l);
  rep(i, 1, n - l + 1) { std::cout << " " << S(i, i + l); }
  std::cout << "\n";
  return 0;
}