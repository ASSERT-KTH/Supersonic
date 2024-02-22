#include <cstdint>
#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using uint32 = std::uint_fast32_t;
using intl32 = std::int_least32_t;

template <typename Monoid, typename Operand>
class link_cut_tree {
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
    void assign(Operand &data) {
      if (b & 1)
        lazy = lazy * data;
      else {
        lazy = data;
        b |= 1;
      }
    }
    void push() {
      if (b & 2) {
        std::swap(left, right);
        left->b ^= 2;
        right->b ^= 2;
        value = ~value;
      }
      if (b & 1) {
        value = value * lazy;
        left->assign(lazy);
        right->assign(lazy);
      }
      b &= ~3;
    }
    void propagate() {
      if (per)
        per->propagate();
      push();
    }
    void splay() {
      node_t *x = this, *pp;
      while (!x->isroot()) {
        if (per->isroot()) {
          if (per->left == this) {
            per->left = right;
            per->recalc();
            right = per;
          } else {
            per->right = left;
            per->recalc();
            left = per;
          }
          x = per;
          per = per->per;
          recalc();
          break;
        }
        x = per->per;
        pp = x->per;
        if (per->left == this) {
          if (x->left == per) {
            x->left = per->right;
            per->left = right;
            per->right = x;
            right = per;
          } else {
            x->right = left;
            per->left = right;
            right = per;
            left = x;
          }
        } else {
          if (x->right == per) {
            x->right = per->left;
            per->right = left;
            per->left = x;
            left = per;
          } else {
            x->left = right;
            per->right = left;
            left = per;
            right = x;
          }
        }
        x->recalc();
        per->recalc();
        recalc();
        per = pp;
        if (pp) {
          if (pp->left == x) {
            pp->left = this;
          } else if (pp->right == x) {
            pp->right = this;
          }
        }
      }