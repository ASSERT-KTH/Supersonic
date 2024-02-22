#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rng()), cnt(1), small(v) {
      left = right = NULL;
    }
  };
  node *root;
  Treap() : root(NULL) {}
  int count(node *t) { return !t ? 0 : t->cnt; }
  int mini(node *t) { return !t ? INF : t->small; }
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
  node *split(node *t, int k, node *res[2]) {
    if (!t) {
      res[0] = res[1] = NULL;
      return NULL;
    }
    node *temp;
    if (k <= count(t->left)) {
      split(t->left, k, res);
      t->left = res[1];
      res[1] = update(t);
      return res[0];
    } else {
      split(t->right, k - count(t->left) - 1, res);
      t->right = res[0];
      res[0] = update(t);
      return res[1];
    }
  }
  node *insert(node *t, int k, int val) {
    node *s[2];
    split(t, k, s);
    t = merge(s[0], new node(val));
    return update(merge(t, s[1]));
  }
  node *erase(node *t, int k) {
    node *s1[2], s2[2];
    split(t, k + 1, s1);
    split(s1[0], k, s2);
    t = merge(s2[0], s1[1]);
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
      Treap::node *a[2], *b[2], *c[2];
      tree.split(tree.root, z, c);
      tree.split(c[0], z - 1, b);
      tree.split(b[0], y, a);
      tree.root = tree.merge(a[0], b[1]);
      tree.root = tree.merge(tree.root, a[1]);
      tree.root = tree.merge(tree.root, c[1]);
    } else if (x == 1) {
      printf("%d\n", tree.rmq(y, z + 1));
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}