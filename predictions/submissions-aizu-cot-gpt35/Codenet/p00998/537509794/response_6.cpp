#include <iostream>
#include <climits>

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return std::min(l, r); }
};

template <typename M>
class avl_tree {
  using T = typename M::type;
  struct node {
    T val, all;
    node *ch[2];
    int size;
    node(T v) : val(v), all(v), ch{nullptr, nullptr}, size(1) {}
  };

  int count(node *t) const { return t ? t->size : 0; }
  T que(node *t) const { return t ? t->all : M::id(); }
  node *update(node *t) {
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    t->all = M::op(que(t->ch[0]), M::op(t->val, que(t->ch[1])));
    return t;
  }

  node *insert(node *t, int k, T v) {
    if (!t)
      return new node(v);
    int c = count(t->ch[0]);
    if (k <= c)
      t->ch[0] = insert(t->ch[0], k, v);
    else
      t->ch[1] = insert(t->ch[1], k - (c + 1), v);
    return update(t);
  }

  node *erase(node *t, int k) {
    if (!t)
      return t;
    int c = count(t->ch[0]);
    if (k < c)
      t->ch[0] = erase(t->ch[0], k);
    else if (k > c)
      t->ch[1] = erase(t->ch[1], k - (c + 1));
    else {
      node *temp = t;
      t = merge(t->ch[0], t->ch[1]);
      delete temp;
    }
    return update(t);
  }

  node *merge(node *l, node *r) {
    if (!l)
      return r;
    if (!r)
      return l;
    if (l->size < r->size)
      std::swap(l, r);
    l->ch[1] = merge(l->ch[1], r);
    return update(l);
  }

  node *root;

public:
  avl_tree() : root(nullptr) {}
  int size() const { return count(root); }
  void insert(int k, T b) { root = insert(root, k, b); }
  void erase(int k) { root = erase(root, k); }
  T find(int l, int r) const {
    if (l < 0 || r >= size())
      return M::id();
    node *left, *mid, *right;
    split(root, l, left, mid);
    split(mid, r - l + 1, mid, right);
    T result = que(mid);
    root = merge(merge(left, mid), right);
    return result;
  }

private:
  void split(node *t, int k, node *&l, node *&r) {
    if (!t) {
      l = r = nullptr;
      return;
    }
    int c = count(t->ch[0]);
    if (k <= c) {
      split(t->ch[0], k, l, t->ch[0]);
      r = update(t);
    } else {
      split(t->ch[1], k - (c + 1), t->ch[1], r);
      l = update(t);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  avl_tree<RMQ> tree;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    tree.insert(i, a);
  }

  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;

    if (x == 0) {
      int val = tree.find(z, z);
      tree.erase(z);
      tree.insert(y, val);
    } else if (x == 1) {
      std::cout << tree.find(y, z) << "\n";
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}