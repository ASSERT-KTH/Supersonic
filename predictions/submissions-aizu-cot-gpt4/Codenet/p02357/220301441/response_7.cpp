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
#define C(x) printf(#x " : %d", x)
using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
template <typename T> class StaticRMQ {
  // Inline function to replace std::min
  inline T min(T x, T y) { return (x < y) ? x : y; }
  // rest of the code remains unchanged
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