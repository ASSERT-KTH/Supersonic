#include <iostream>
#include <vector>

struct ass {
  int data;
  ass(int a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

struct douse {
  int all, r, l, sum, siz;
  bool id;
  douse() : id(true) {}
  douse(int a, int lef, int rig, int s, int si)
      : all(a), l(lef), r(rig), sum(s), siz(si), id(false) {}
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
    ret.id = false;
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

class link_cut_tree {
  struct node_t {
    node_t *left, *right, *per;
    douse value, sum;
    ass lazy;
    bool b;
    node_t()
        : left(nullptr), right(nullptr), per(nullptr), value(douse()),
          sum(douse()), b(false) {}
    inline bool isroot() { return !b; }
    douse reflect() {
      if (b) {
        if (b)
          return ~(sum * lazy);
        return sum * lazy;
      }
      if (b)
        return ~sum;
      return sum;
    }
    void assign(ass &data) {
      if (b)
        lazy = lazy * data;
      else {
        lazy = data;
        b = true;
      }
    }
    void push() {
      if (b) {
        std::swap(left, right);
        left->b ^= true;
        right->b ^= true;
        value = ~value;
      }
      if (b) {
        value = value * lazy;
        left->assign(lazy);
        right->assign(lazy);
      }
      b = false;
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
      x->b = true;
    }
    void expose(node_t *prev) {
      splay();
      right->b = false;
      right = prev;
      recalc();
      if (per)
        per->expose(this);
      else {
        b = false;
      }
    }
    void recalc() {
      sum = value;
      if (left != nullptr) {
        sum = left->reflect() + sum;
        left->per = this;
      }
      if (right != nullptr) {
        sum = sum + right->reflect();
        right->per = this;
      }
    }
  };
  std::vector<node_t> tree;
  void expose(node_t *n) {
    n->propagate();
    scan();
    n->expose(nullptr);
    scan();
    n->splay();
    n->b = false;
    scan();
    n->recalc();
  }

public:
  link_cut_tree(int size) : tree(size) {}
  link_cut_tree(std::vector<douse> &a) : tree(a.size()) {
    for (int i = 0; i < a.size(); ++i) {
      tree[i].value = tree[i].sum = a[i];
    }
  }
  void link(int child, int per) {
    evert(child);
    tree[child].per = &tree[per];
  }
  void cut(int child) {
    node_t *n = &tree[child];
    expose(n);
    n->left->per = nullptr;
    n->left = nullptr;
    n->sum = n->value;
  }
  void update(int u, int v, const ass &data) {
    evert(u);
    expose(&tree[v]);
    tree[v].lazy = data;
    tree[v].b = true;
  }
  douse path(int u, int v) {
    evert(u);
    expose(&tree[v]);
    scan();
    return tree[v].sum;
  }
  void evert(int v) {
    scan();
    expose(&tree[v]);
    scan();
    tree[v].b ^= true;
  }
  void scan(void) {}
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);