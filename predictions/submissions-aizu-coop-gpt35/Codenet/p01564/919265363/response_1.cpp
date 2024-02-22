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
using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;
template <typename Monoid, typename Operand>
class link_cut_tree {
  struct node_t {
    node_t *left, *right, *per;
    Monoid value, sum;
    Operand lazy;
    node_t()
        : left(nil), right(nil), per(nullptr), value(Monoid()), sum(Monoid()) {}
    inline bool isroot() { return !(this->per) || (this->per->left != this && this->per->right != this); }
    Monoid reflect() {
      if (this->lazy.data != 0) {
        return this->value * this->lazy;
      }
      return this->value;
    }
    void assign(Operand data) {
      this->lazy = data;
    }
    void push() {
      if (this->lazy.data != 0) {
        this->left->assign(this->lazy);
        this->right->assign(this->lazy);
        this->value = this->reflect();
        this->lazy = Operand();
      }
    }
    void propagate() {
      if (this->per)
        this->per->propagate();
      this->push();
    }
    void splay() {
      while (!this->isroot()) {