#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::min;
using std::pair;
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
    if (!t)
      return make_pair((node *)NULL, (node *)NULL);
    if (k <= count(t->left)) {
      auto s = split(t->left, k);
      t->left = s.second;
      return make_pair(s.first, update(t));
    } else {
      auto s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      return make_pair(update(t), s.second);
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

  // Rest of the code remains the same...
};