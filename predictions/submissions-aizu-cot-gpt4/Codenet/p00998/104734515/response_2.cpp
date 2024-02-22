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
  struct Pair {
    node* first;
    node* second;
    Pair(node* first, node* second) : first(first), second(second) {}
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
  Pair split(node *t, int k) {
    if (!t)
      return Pair((node *)NULL, (node *)NULL);
    if (k <= count(t->left)) {
      Pair s = split(t->left, k);
      t->left = s.second;
      return Pair(s.first, update(t));
    } else {
      Pair s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      return Pair(update(t), s.second);
    }
  }
  // ...
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  Treap tree;
  scanf("%d %d", &n, &q);
  // ...
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      z++;
      Treap::Pair a, b, c;
      c = tree.split(tree.root, z);
      b = tree.split(c.first, z - 1);
      a = tree.split(b.first, y);
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