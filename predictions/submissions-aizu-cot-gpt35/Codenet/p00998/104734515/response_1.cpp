#include <iostream>
#include <random>

const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node* left;
    node* right;
    int priority;
    int cnt;
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

  int count(node* t) { return t ? t->cnt : 0; }

  int mini(node* t) { return t ? t->small : INF; }

  void update(node* t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = std::min(std::min(mini(t->left), mini(t->right)), t->value);
  }

  node* merge(node* l, node* r) {
    if (!l || !r)
      return l ? l : r;

    if (l->priority > r->priority) {
      l->right = merge(l->right, r);
      update(l);
      return l;
    } else {
      r->left = merge(l, r->left);
      update(r);
      return r;
    }
  }

  std::pair<node*, node*> split(node* t, int k) {
    if (!t)
      return {nullptr, nullptr};

    if (k <= count(t->left)) {
      auto s = split(t->left, k);
      t->left = s.second;
      update(t);
      return {s.first, t};
    } else {
      auto s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      update(t);
      return {t, s.second};
    }
  }

  node* insert(node* t, int k, int val) {
    auto s = split(t, k);
    t = new node(val);
    t->left = s.first;
    t->right = s.second;
    update(t);
    return t;
  }

  node* erase(node* t, int k) {
    auto s1 = split(t, k + 1);
    auto s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    update(t);
    return t;
  }

  node* find(node* t, int k) {
    int c = count(t->left);

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

    int size = count(t->left);
    int ret = std::min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));

    if (l <= size && size < r)
      ret = std::min(ret, t->value);

    return ret;
  }

  void insert(int k, int v) { root = insert(root, k, v); }

  void erase(int k) { root = erase(root, k); }

  node* find(int k) { return find(root, k); }

  int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
  int n, q;
  Treap tree;
  std::cin >> n >> q;

  for (int i = 0, a; i < n; i++) {
    std::cin >> a;
    tree.insert(i, a);
  }

  std::random_device rd;
  std::mt19937 gen(rd());

  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;

    if (x == 0) {
      z++;
      auto [a, b] = tree.split(tree.root, z);
      auto [c, d] = tree.split(a, z - 1);
      auto [e, f] = tree.split(c, y);
      tree.root = tree.merge(e, d);
      tree.root = tree.merge(tree.root, f);
      tree.root = tree.merge(tree.root, b);
    } else if (x == 1) {
      std::cout << tree.rmq(y, z + 1) << std::endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}