#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
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

  int count(node *t) {
    return !t ? 0 : t->cnt;
  }

  int mini(node *t) {
    return !t ? INF : t->small;
  }

  void update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
  }

  void split(node *t, int k, node *&left, node *&middle, node *&right) {
    if (!t) {
      left = middle = right = NULL;
      return;
    }

    if (k <= count(t->left)) {
      split(t->left, k, left, middle, t->left);
      right = t;
    } else {
      split(t->right, k - count(t->left) - 1, t->right, middle, right);
      left = t;
    }

    update(t);
  }

  node *merge(node *l, node *r) {
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

  void insert(node *&t, int k, int val) {
    node *left, *middle, *right;
    split(t, k, left, middle, right);
    t = merge(merge(left, new node(val)), right);
    update(t);
  }

  void erase(node *&t, int k) {
    node *left, *middle, *right;
    split(t, k + 1, left, middle, right);
    split(left, k, left, middle, right);
    t = merge(left, right);
    update(t);
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
    int ret = INF;

    while (true) {
      int size = count(t->left);

      if (l <= size && size < r)
        ret = min(ret, t->value);

      if (l <= size)
        t = t->left;
      else if (size < r)
        t = t->right;
      else
        break;
    }

    return ret;
  }

  void insert(int k, int v) {
    insert(root, k, v);
  }

  void erase(int k) {
    erase(root, k);
  }

  node *find(int k) {
    return find(root, k);
  }

  int rmq(int l, int r) {
    return rmq(root, l, r);
  }
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
      node *a, *b, *c;
      tree.split(tree.root, z, a, b, c);
      tree.split(a, y, a, b, c);
      tree.root = tree.merge(tree.merge(a, b), tree.merge(c, b)); // merge b twice instead of merging a and b and then merging b again
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}