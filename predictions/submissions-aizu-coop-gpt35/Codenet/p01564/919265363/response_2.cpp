#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using uint32 = std::uint_fast32_t;
using intl32 = std::int_least32_t;

template <typename Monoid, typename Operand>
class link_cut_tree {
  struct node_t {
    uint32 left, right, per;
    Monoid sum;
    Operand lazy;
    bool id;
    node_t()
        : left(0), right(0), per(0), sum(Monoid()), lazy(Operand()), id(true) {}
    Monoid reflect() {
      if (id) {
        return sum * lazy;
      }
      return ~sum * lazy;
    }
    void assign(Operand &data) {
      if (id) {
        lazy = lazy * data;
      } else {
        lazy = data;
        id = true;
      }
    }
    void push() {
      if (!id) {
        std::swap(left, right);
        sum = ~sum;
        id = true;
      }
      if (lazy != Operand()) {
        sum = sum * lazy;
      }
      lazy = Operand();
    }
    void propagate() {
      push();
      if (per != 0) {
        tree[per].propagate();
      }
    }
    void splay() {
      while (per != 0) {
        uint32 x = per;
        uint32 pp = tree[x].per;
        if (pp == 0) {
          if (tree[pp].left == x) {
            tree[pp].left = right;
            right = pp;
          } else {
            tree[pp].right = left;
            left = pp;
          }
          per = 0;
        } else {
          uint32 ppp = tree[pp].per;
          if (tree[pp].left == x) {
            if (tree[pp].per == 0) {
              tree[pp].left = right;
              right = pp;
              per = ppp;
            } else if (tree[ppp].left == pp) {
              tree[ppp].left = right;
              tree[pp].left = tree[right].right;
              tree[right].right = pp;
              per = ppp;
            } else {
              tree[ppp].right = right;
              tree[pp].left = tree[right].right;
              tree[right].right = pp;
              per = ppp;
            }
            tree[pp].recalc();
            recalc();
          } else {
            if (tree[pp].per == 0) {
              tree[pp].right = left;
              left = pp;
              per = ppp;
            } else if (tree[ppp].left == pp) {
              tree[ppp].left = left;
              tree[pp].right = tree[left].left;
              tree[left].left = pp;
              per = ppp;
            } else {
              tree[ppp].right = left;
              tree[pp].right = tree[left].left;
              tree[left].left = pp;
              per = ppp;
            }
            tree[pp].recalc();
            recalc();
          }
        }