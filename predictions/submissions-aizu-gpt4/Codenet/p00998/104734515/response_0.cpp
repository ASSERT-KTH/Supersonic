#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand()), cnt(1), small(v) {
      left = right = nullptr;
    }
  };
  node *root;

  Treap() : root(nullptr) {}
  
  inline int count(node *t) const { return t ? t->cnt : 0; }
  inline int mini(node *t) const { return t ? t->small : INF; }

  node *update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min({mini(t->left), mini(t->right), t->value});
    return t;
  }

  node *merge(node *l, node *r) {
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

  pair<node *, node *> split(node *t, int k) {
    if (!t)
      return {nullptr, nullptr};
    if (k <= count(t->left)) {
      auto s = split(t->left, k);
      t->left = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      return {update(t), s.second};
    }
  }

  node *modify(node *t, int k, int val, bool erase) {
    auto s1 = split(t, k + !erase);
    auto s2 = split(s1.first, k);
    node *new_node = erase ? s2.first : merge(s2.first, new node(val));
    return update(merge(new_node, s1.second));
  }

  node *find(node *t, int k) const {
    int c = count(t->left);
    if (k < c)
      return find(t->left, k);
    else if (k > c)
      return find(t->right, k - c - 1);
    else
      return t;
  }

  int rmq(node *t, int l, int r) const {
    if (l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);
    int size = count(t->left);
    int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
    if (l <= size && size < r)
      ret = min(ret, t->value);
    return ret;
  }

  void modify(int k, int v, bool erase) { root = modify(root, k, v, erase); }
  node *find(int k) const { return find(root, k); }
  int rmq(int l, int r) const { return rmq(root, l, r); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  Treap tree;
  for (int i = 0, a; i < n; ++i) {
    cin >> a;
    tree.modify(i, a, false);
  }

  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0) {
      z++;
      auto c = tree.split(tree.root, z);
      auto b = tree.split(c.first, z - 1);
      auto a = tree.split(b.first, y);
      tree.root = tree.merge(tree.merge(a.first, b.second), tree.merge(a.second, c.second));
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << '\n';
    } else {
      tree.modify(y, z, true);
      tree.modify(y, z, false);
    }
  }
  
  return 0;
}