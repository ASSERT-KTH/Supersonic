#include <iostream>
#include <random>
using namespace std;

const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node* left;
    node* right;
    int priority;
    size_t cnt;
    int small;

    node(int v)
        : value(v),
          left(nullptr),
          right(nullptr),
          priority(0),
          cnt(1),
          small(v) {}
  };

  node* root;

  Treap() : root(nullptr) {}

  size_t count(node* t) { return t ? t->cnt : 0; }

  int mini(node* t) { return t ? t->small : INF; }

  node* update(node* t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
    return t;
  }

  node* merge(node* l, node* r) {
    if (!l || !r)
      return l ? l : r;

    if (l->priority > r->priority) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  node* split(node* t, size_t k) {
    if (!t)
      return nullptr;

    if (k <= count(t->left)) {
      node* left = split(t->left, k);
      t->left = left;
      return update(t);
    } else {
      node* right = split(t->right, k - count(t->left) - 1);
      t->right = right;
      return update(t);
    }
  }

  node* insert(node* t, size_t k, int val) {
    node* s = split(t, k);
    t = merge(s, new node(val));
    return update(t);
  }

  node* erase(node* t, size_t k) {
    node* s1, *s2;
    s1 = split(t, k + 1);
    s2 = split(s1, k);
    t = merge(s2, s1);
    return update(t);
  }

  node* find(node* t, size_t k) {
    size_t c = count(t->left);
    if (k < c)
      return find(t->left, k);
    else if (k > c)
      return find(t->right, k - c - 1);
    else
      return t;
  }

  int rmq(node* t, int l, int r) {
    if (l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);

    size_t size = count(t->left);
    int ret =
        min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));

    if (l <= size && size < r)
      ret = min(ret, t->value);

    return ret;
  }

  void insert(size_t k, int v) { root = insert(root, k, v); }

  void erase(size_t k) { root = erase(root, k); }

  node* find(size_t k) { return find(root, k); }

  int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
  int n, q;
  Treap tree;
  cin >> n >> q;

  for (int i = 0, a; i < n; i++) {
    cin >> a;
    tree.insert(i, a);
  }

  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;

    if (x == 0) {
      z++;
      Treap::node* a, *b, *c;
      c = tree.split(tree.root, z);
      b = tree.split(c->left, z - 1);
      a = tree.split(b->left, y);

      tree.root = tree.merge(a->left, b->right);
      tree.root = tree.merge(tree.root, a->right);
      tree.root = tree.merge(tree.root, c->right);
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}