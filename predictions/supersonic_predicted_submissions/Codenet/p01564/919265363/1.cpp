#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
      x->b |= 4;
    }
    void expose(node_t *prev) {
      splay();
      right->b &= ~4;
      right = prev;
      recalc();
      if (per)
        per->expose(this);
      else {
        b &= ~4;
      }
    }
    void recalc() {
      sum = value;
      if (left != nil) {
        sum = left->reflect() + sum;
        left->per = this;
      }
      if (right != nil) {
        sum = sum + right->reflect();
        right->per = this;
      }
    }
  };
  static node_t *nil;
  std::vector<node_t> tree;
  void expose(node_t *n) {
    n->propagate();
    scan();
    n->expose(nil);
    scan();
    n->splay();
    n->b &= ~4;
    scan();
    n->recalc();
  }
  struct vis {
    int32 l, r, p, rev;
  };
  std::vector<vis> v;

public:
  link_cut_tree(uint32 size) : tree(size) {}
  link_cut_tree(std::vector<Monoid> &a) : tree(a.size()) {
    for (uint32 i = 0; i < a.size(); ++i) {
      tree[i].value = tree[i].sum = a[i];
    }
  }
  void link(uint32 child, uint32 per) {
    evert(child);
    tree[child].per = &tree[per];
  }
  void cut(uint32 child) {
    node_t *n = &tree[child];
    expose(n);
    n->left->per = nullptr;
    n->left = nil;
    n->sum = n->value;
  }
  void update(uint32 u, uint32 v, const Operand &data) {
    evert(u);
    expose(&tree[v]);
    tree[v].lazy = data;
    tree[v].b |= 1;
  }
  Monoid path(uint32 u, uint32 v) {
    evert(u);
    expose(&tree[v]);
    scan();
    return tree[v].sum;
  }
  void evert(uint32 v) {
    scan();
    expose(&tree[v]);
    scan();
    tree[v].b ^= 2;
  }
  int32 ch(node_t *n) {
    if (!n)
      return 100;
    if (n == nil)
      return -1;
    return n - &tree[0];
  }
  void scan(void) {
    return;
    v = std::vector<vis>(tree.size());
    for (uint32 i = 0; i < tree.size(); ++i) {
      v[i] = {ch(tree[i].left), ch(tree[i].right), ch(tree[i].per),
              tree[i].b & 2};
    }
  }
};
template <typename Monoid, typename Operand>
typename link_cut_tree<Monoid, Operand>::node_t *
    link_cut_tree<Monoid, Operand>::nil = [] {
      nil = new link_cut_tree<Monoid, Operand>::node_t;
      nil->left = nil;
      nil->right = nil;
      nil->per = nullptr;
      nil->sum = Monoid();
      nil->b = 0;
      return nil;
    }();
struct ass {
  intl32 data;
  ass(intl32 a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};
struct douse {
  intl32 all, r, l, sum, siz;
  bool id;
  douse() : id(1) {}
  douse(int32 a, int32 lef, int32 rig, int32 s, int32 si)
      : all(a), l(lef), r(rig), sum(s), siz(si), id(0) {}
  douse operator~() {
    douse ret = *this;
    std::swap(ret.l, ret.r);
    return ret;
  }
  douse operator+(const douse &other) {
    if (id)
      return other;
    if (other.id)
      return *this;
    douse ret;
    ret.all = std::max(std::max(all, other.all),
                       std::max(r + other.l, std::max(r, other.l)));
    ret.r = std::max(other.r, r > 0 ? r + other.sum : other.sum);
    ret.l = std::max(l, other.l > 0 ? sum + other.l : sum);
    ret.sum = sum + other.sum;
    ret.siz = siz + other.siz;
    ret.id = 0;
    return ret;
  }
  douse operator*(const ass &other) {
    douse ret;
    ret.all = ret.r = ret.l = other.data > 0 ? other.data * siz : other.data;
    ret.sum = other.data * siz;
    ret.siz = siz;
    ret.id = id;
    return ret;
  }
};
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);
  int32 t1;
  for (uint32 i = 0; i < n; ++i) {
    std::cin >> t1;
    a[i] = douse(t1, t1, t1, t1, 1);
  }
  link_cut_tree<douse, ass> L(a);
  uint32 t2, t3;
  for (uint32 i = 0; i < n - 1; ++i) {
    std::cin >> t2 >> t3;
    L.link(t2 - 1, t3 - 1);
    L.scan();
  }
  uint32 t4;
  for (uint32 i = 0; i < q; ++i) {
    L.scan();
    std::cin >> t2 >> t3 >> t4 >> t1;
    if (t2 == 1) {
      L.update(t3 - 1, t4 - 1, ass(t1));
    } else {
      std::cout << L.path(t3 - 1, t4 - 1).all << "\n";
    }
  }
  return 0;
}
