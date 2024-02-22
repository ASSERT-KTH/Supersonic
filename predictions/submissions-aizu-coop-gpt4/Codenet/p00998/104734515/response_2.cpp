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
    // Using a better random generator
    std::mt19937 rng;
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
  // Other functions remain the same
  // ....
  
  int rmq(node *t, int l, int r) {
    int countT = count(t);
    if (l >= countT || r <= 0)
      return INF;
    if (l <= 0 && r >= countT)
      return mini(t);
    int size = count(t->left);
    int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
    if (l <= size && size < r)
      ret = min(ret, t->value);
    return ret;
  }
  // Other functions remain the same
  // ....
};