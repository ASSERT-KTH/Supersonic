#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct ass {
  int data;
  ass(int a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

struct douse {
  int all, r, l, sum, siz;
  douse() : id(1) {}
  douse(int a, int lef, int rig, int s, int si)
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

template <typename Monoid, typename Operand>
class link_cut_tree {
  struct node_t {
    Monoid value, sum;
    Operand lazy;
    std::uint_least8_t b;
    node_t()
        : value(Monoid()), sum(Monoid()), b(0) {}
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

    node_t *left, *right, *per;
  };

  std::vector<node_t> tree;

public:
  link_cut_tree(uint32_t size) : tree(size + 1) {}
  link_cut_tree(std::vector<Monoid> &a) : tree(a.size() + 1) {
    for (uint32_t i = 1; i <= a.size(); ++i) {
      tree[i].value = tree[i].sum = a[i - 1];
    }
  }
  void link(uint32_t child, uint32_t per) {
    evert(child);
    tree[child].per = &tree[per];
  }
  void cut(uint32_t child) {
    node_t *n = &tree[child];
    expose(n);
    n->left->per = nullptr;
    n->left = nil;
    n->sum = n->value;
  }
  void update(uint32_t u, uint32_t v, const Operand &data) {
    evert(u);
    expose(&tree[v]);
    tree[v].lazy = data;
    tree[v].b |= 1;
  }
  Monoid path(uint32_t u, uint32_t v) {
    evert(u);
    expose(&tree[v]);
    return tree[v].sum;
  }
  void evert(uint32_t v) {
    expose(&tree[v]);
    tree[v].b ^= 2;
  }

private:
  static node_t *nil;
  void expose(node_t *n) {
    n->propagate();
    n->expose(nil);