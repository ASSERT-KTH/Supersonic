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
      0xFFFC0000, 0xFEF80000, 0xFFF00000, 0xFFE00000, 0xFFC00000, 0xFF800000,
      0xFF000000, 0xFE000000, 0xFC