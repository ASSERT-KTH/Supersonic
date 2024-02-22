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
  uint32 bitmaskr[32] = {
      0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFC, 0xFFFFFFF8, 0xFFFFFFF0, 0xFFFFFFE0,
      0xFFFFFFC0, 0xFFFFFF80, 0xFFFFFF00, 0xFFFFFE00, 0xFFFFFC00, 0xFFFFF800,
      0xFFFFF000, 0xFFFFE000, 0xFFFFC000, 0xFFFF8000, 0xFFFF0000, 0xFFFE0000,
      0xFFFC0000, 0xFFF80000, 0xFFF00000, 0xFFE00000, 0xFFC00000, 0xFF800000,
      0xFF000000, 0xFE000000, 0xFC000000, 0xF8000000, 0xF0000000, 0xE0000000,
      0xC0000000, 0x80000000,
  };
  uint32 bitmaskl[32] = {
      0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F,
      0x0000007F, 0x000000FF, 0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF,
      0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF, 0x0001FFFF, 0x0003FFFF,
      0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF,
      0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF,
      0x7FFFFFFF, 0xFFFFFFFF};

public:
  StaticRMQ(std::vector<T> &array) {
    // identical code
  }
  ~StaticRMQ() {
    free(a);
    free(R);
    free(L);
    free(part);
    free(table[0]);
    free(table);
  }
  uint32 operator()(uint32 begin, uint32 end) {
   // identical code
  }
};

int main(void) {
  uint32 n, l;
  scanf("%d %d", &n, &l);
  std::vector<uint32> a(n);
  rep(i, 0, n) { scanf("%d", &a[i]); }
  StaticRMQ<uint32> S(a);
  printf("%d", S(0, l));
  rep(i, 1, n - l + 1) { printf(" %d", S(i, i + l)); }
  printf("\n");
  return 0;
}
