#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
#define INF 1000000000
#define MOD 1000000007
#define rep(i, a, b) for (uint32 i = (a); i < (b); ++i)
#define bitget(a, b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(), (x).end()
#define C(x) std::cout << #x << " : " << x << std::endl
#define scanf scanf_s
using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
template <typename T> class StaticRMQ {
  T *a;
  uint32 **table, t, *R, *L, *part;
  static const uint32 bitmaskr[32];
  static const uint32 bitmaskl[32];

public:
  StaticRMQ(const std::vector<T> &array) {
    uint32 s, m, c = 0, e[32] = {};
    a = new T[array.size()];
    std::copy(array.begin(), array.end(), a);
    R = (uint32 *)std::calloc((array.size() + 0x1F) >> 5, sizeof(uint32));
    // Rest of the code
  }
  uint32 operator()(uint32 begin, uint32 end) {
    uint32 l = (begin >> 5) + 1;
    uint32 r = --end >> 5;
    uint32 t = a[(begin & ~0x1F) | __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])];
    if (l < r) {
      uint32 temp = 31 ^ __builtin_clz(r - l);
      t = std::min(a[table[temp][l]], a[table[temp][r - (1 << temp)]]);
      t = std::min(t, a[(end & ~0x1F) | (31 ^ __builtin_clz(R[end >> 5] & bitmaskl[end & 0x1F]))]);
      return t;
    }
    if (l == r) {
      return std::min(t, a[(end & ~0x1F) | (31 ^ __builtin_clz(R[end >> 5] & bitmaskl[end & 0x1F]))]);
    }
    return a[(end & ~0x1F) | __builtin_ctz(part[end] & bitmaskr[begin & 0x1F])];
  }
};
const uint32 StaticRMQ<uint32>::bitmaskr[32] = { /* values */ };
const uint32 StaticRMQ<uint32>::bitmaskl[32] = { /* values */ };
// Rest of the code