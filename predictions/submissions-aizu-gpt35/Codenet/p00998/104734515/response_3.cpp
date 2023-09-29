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
    node(int v) : value(v), priority(rand()), cnt(1), small(v), left(nullptr), right(nullptr) {}
  };
  node *root;
  Treap() : root(nullptr) {}
  int count(node *t) { return t ? t->cnt : 0; }
  int mini(node *t) { return t ? t->small : INF; }
  node *update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
    return t;
  }
  node *merge(node *l, node *r) {
    if (!l) return r;
    if (!r) return l;
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
      auto s = split(t->left, k);
      t->left = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      return {update(t), s.second};
    }
  }
  node *insert(node *t, int k, int val) {
    auto s = split(t, k);
    t = merge(s.first, new node(val));
    return update(merge(t, s.second));
  }
  node *erase(node *t, int k) {
    auto s1 = split(t, k + 1);
    auto s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    return update(t);
  }
  node *find(node *t, int k) {
    int c = count(t->left);
    if (k < c) return find(t->left, k);
    else if (k > c) return find(t->right, k - c - 1);
    else return t;
  }
  int rmq(node *t, int l, int r) {
    if (l >= count(t) || r <= 0) return INF;
    if (l <= 0 && r >= count(t)) return mini(t);
    int size = count(t->left);
    int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
    if (l <= size && size < r) ret = min(ret, t->value);
    return ret;
  }
  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  node *find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  scanf("%d %d", &n, &q);
  Treap tree;
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      ++z;
      auto c = tree.split(tree.root, z);
      auto b = tree.split(c.first, z - 1);
      auto a = tree.split(b.first, y);
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      printf("%d\n", tree.rmq(y, z + 1));
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}