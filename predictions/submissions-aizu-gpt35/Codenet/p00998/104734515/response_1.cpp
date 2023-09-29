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
      left = right = NULL;
    }
  };
  node *root;
  Treap() : root(NULL) {}
  int count(node *t) { return t ? t->cnt : 0; }
  int mini(node *t) { return t ? t->small : INF; }
  node *update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
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
    if (!t) return {nullptr, nullptr};
    if (k <= count(t->left)) {
      auto [left, right] = split(t->left, k);
      t->left = right;
      return {left, update(t)};
    } else {
      auto [left, right] = split(t->right, k - count(t->left) - 1);
      t->right = left;
      return {update(t), right};
    }
  }
  node *insert(node *t, int k, int val) {
    auto [left, right] = split(t, k);
    t = merge(left, new node(val));
    return update(merge(t, right));
  }
  node *erase(node *t, int k) {
    auto [left1, right1] = split(t, k + 1);
    auto [left2, right2] = split(left1, k);
    t = merge(left2, right1);
    return update(t);
  }
  node *find(node *t, int k) {
    int c = count(t->left);
    if (k < c)
      return find(t->left, k);
    else if (k > c)
      return find(t->right, k - c - 1);
    else
      return t;
  }
  int rmq(node *t, int l, int r) {
    if (!t) return INF;
    if (l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);
    int size = count(t->left);
    int ret =
        min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
    if (l <= size && size < r)
      ret = min(ret, t->value);
    return ret;
  }
  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  node *find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};
int main() {
  int n, q;
  Treap tree;
  scanf("%d %d", &n, &q);
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      z++;
      auto [c_left, c_right] = tree.split(tree.root, z);
      auto [b_left, b_right] = tree.split(c_left, z - 1);
      auto [a_left, a_right] = tree.split(b_left, y);
      tree.root = tree.merge(a_left, b_right);
      tree.root = tree.merge(tree.root, a_right);
      tree.root = tree.merge(tree.root, c_right);
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}