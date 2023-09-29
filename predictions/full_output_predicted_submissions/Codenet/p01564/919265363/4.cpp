#include <algorithm>
#include <array>
#include <climits>
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
#include <type_traits>
#include <utility>
#include <vector>
using namespace32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;
template <typename Monoid, typename Operand> class link_cut_tree {
  struct node_t {
    node_t *left, *right, *per;
    Monoid value, sum;
    Operand lazy;
    std::uint_least8_t b;
    node_t()
        : left(nil), right(nil), per(nullptr), value(Monoid()), sum(Monoid()),
          b(0) {}
    inline bool isroot() { return !(b & 4); }
    Monoid reflect() {
      if (b & 1) {
        if (b & 2)
          return ~(sum * lazy);
        return sum * lazy;
      }
      if (b & 2)
        return ~sum;
      return sum;
    }
    void assign(Oper