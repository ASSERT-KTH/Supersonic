#include <iostream>
#include <vector>

using uint32 = std::uint_fast32_t;

class StaticRMQ {
  std::vector<uint32> a;
  std::vector<std::vector<uint32>> table;
  std::vector<uint32> R, L, part;

public:
  StaticRMQ(std::vector<uint32> &array) {
    a = array;
    uint32 n = array.size();
    uint32 s = 31 - __builtin_clz(n >> 5);
    table.resize(s + 1);
    R.resize((n + 31) >> 5);
    L.resize((n + 31) >> 5);
    part.resize(n);

    for (uint32 t = 0; t < n; ++t) {
      part[t] = 1 << (t & 0x1F);
      if (!(t & 0x1F)) {
        R[t >> 5] = 1;
        table[0].push_back(t);
      }

      uint32 m = a[t];
      uint32 c = table[0].size();
      while (c) {
        if (!(a[t] < a[table[0][--c]])) {
          part[t] |= part[table[0][c]];
          break;
        }
      }
      table[0][c++] = t;
      if (a[t] < m) {
        m = a[t];
        R[t >> 5] |= 1 << (t & 0x1F);
        table[0][c] = t;
      }
      if (!((~t) & 0x1F)) {
        L[t >> 5] = part[t];
      }
    }

    for (uint32 t = 0; t < s; ++t) {
      table[t + 1].resize(table[t].size() - (1 << t));
      for (uint32 m = 0; m < table[t + 1].size(); ++m) {
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
      uint32 t = 31 - __builtin_clz(r - l);
      uint32 t1 = a[table[t][l]];
      uint32 t2 = a[table[t][r - (1 << t)]];
      t = std::min(t1, t2);
      uint32 t3 =
          a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & (0xFFFFFFFF >> (begin & 0x1F)))];
      t = std::min(t3, t);
      uint32 t4 =
          a[(end & ~0x1F) | (31 - __builtin_clz(R[end >> 5] & (0xFFFFFFFF << (31 - (end & 0x1F)))))];
      t = std::min(t4, t);
      return t;
    }
    if (l == r) {
      uint32 t = a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & (0xFFFFFFFF >> (begin & 0x1F)))];
      uint32 t1 =
          a[(end & ~0x1F) | (31 - __builtin_clz(R[end >> 5] & (0xFFFFFFFF << (31 - (end & 0x1F)))))];
      return std::min(t, t1);
    }
    return a[(end & ~0x1F) | __builtin_ctz(part[end] & (0xFFFFFFFF >> (begin & 0x1F)))];
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  uint32 n, l;
  std::scanf("%u %u", &n, &l);
  std::vector<uint32> a(n);
  for (uint32 i = 0; i < n; ++i) {
    std::scanf("%u", &a[i]);
  }

  StaticRMQ S(a);

  std::printf("%u", S(0, l));
  for (uint32 i = 1; i < n - l + 1; ++i) {
    std::printf(" %u", S(i, i + l));
  }
  std::printf("\n");
  
  return 0;
}