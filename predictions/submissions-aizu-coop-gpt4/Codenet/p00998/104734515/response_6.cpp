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

  int count(node *t) { return !t ? 0 : t->cnt; }
  int mini(node *t) { return !t ? INF : t->small; }

  node *update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(t->value, min(mini(t->left), mini(t->right)));
    return t;
  }

  node *merge(node *l, node *r) {
    if (!l || !r) return l ? l : r;
    if (l->priority > r->priority) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  void split(node *t, int k, node *&l, node *&r) {
    if (!t) {
      l = r = NULL;
      return;
    }
    if (k <= count(t->left)) {
      split(t->left, k, l, t->left);
      r = update(t);
    } else {
      split(t->right, k - count(t->left) - 1, t->right, r);
      l = update(t);
    }
  }

  node *insert(node *t, int k, int val) {
    node *l, *r;
    split(t, k, l, r);
    return update(merge(merge(l, new node(val)), r));
  }

  node *erase(node *t, int k) {
    node *l, *m, *r;
    split(t, k + 1, l, r);
    split(l, k, l, m);
    return update(merge(l, r));
  }

  node *find(node *t, int k) {
    while(t) {
      int c = count(t->left);
      if(k < c) t = t->left;
      else if(k > c) {
        k -= c + 1;
        t = t->right;
      } else return t;
    }
    return NULL;
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
      Treap::node *a, *b, *c, *d, *e;
      tree.split(tree.root, z, d, e);
      tree.split(d, z - 1, c, d);
      tree.split(c, y, a, b);
      tree.root = tree.merge(tree.merge(a, d), tree.merge(b, e));
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}