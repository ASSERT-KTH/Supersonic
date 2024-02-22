#include <algorithm>
#include <iostream>
#include <vector>

struct douse {
  int32_t all, r, l, sum, siz;
  douse() : all(0), r(0), l(0), sum(0), siz(0) {}
  douse(int32_t a, int32_t lef, int32_t rig, int32_t s, int32_t si)
      : all(a), l(lef), r(rig), sum(s), siz(si) {}
  douse operator+(const douse &other) {
    douse ret;
    ret.all = std::max(std::max(all, other.all),
                       std::max(r + other.l, std::max(r, other.l)));
    ret.r = std::max(other.r, r > 0 ? r + other.sum : other.sum);
    ret.l = std::max(l, other.l > 0 ? sum + other.l : sum);
    ret.sum = sum + other.sum;
    ret.siz = siz + other.siz;
    return ret;
  }
};

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
      if (left) {
        sum = left->reflect() + sum;
        left->per = this;
      }
      if (right) {
        sum = sum + right->reflect();
        right->per = this;
      }
    }
  };
  static node_t *nil;
  std::vector<node_t> tree;

public:
  link_cut_tree(uint32_t size) : tree(size) {}
  link_cut_tree(std::vector<Monoid> &a) : tree(a.size()) {
    for (uint32_t i = 0; i < a.size(); ++i) {
      tree[i].value = tree[i].sum = a[i];
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
  void expose(node_t *n) {
    n->propagate();
    while (n->per) {
      node_t *p = n->per;
      p->propagate();
      n->per = nullptr;
      p->splay();
      p->right = n;
      p->recalc();
      n = p;
    }
    n->splay();
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32_t n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);