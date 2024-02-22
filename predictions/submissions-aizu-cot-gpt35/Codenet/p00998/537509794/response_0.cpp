#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return std::min(l, r); }
};

class avl_tree {
  using T = typename RMQ::type;
  struct node {
    T val, all;
    node *ch[2];
    int dep, size;
    node(T v, node *l = nullptr, node *r = nullptr)
        : val(v), all(v), ch{l, r}, dep(1), size(1) {}
  };
  static int depth(node *t) { return t ? t->dep : 0; }
  static int count(node *t) { return t ? t->size : 0; }
  static T que(node *t) { return t ? t->all : RMQ::id(); }
  static node *update(node *t) {
    int depthL = depth(t->ch[0]);
    int depthR = depth(t->ch[1]);
    t->dep = std::max(depthL, depthR) + 1;
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    t->all = RMQ::op(que(t->ch[0]), RMQ::op(t->val, que(t->ch[1])));
    return t;
  }
  static node *rotate(node *t, int b) {
    node *s = t->ch[1 - b];
    t->ch[1 - b] = s->ch[b];
    s->ch[b] = t;
    update(t);
    return update(s);
  }
  static node *fix(node *t) {
    if (!t)
      return t;
    int depthL = depth(t->ch[0]);
    int depthR = depth(t->ch[1]);
    if (depthL - depthR == 2) {
      if (depth(t->ch[0]->ch[1]) > depth(t->ch[0]->ch[0])) {
        t->ch[0] = rotate(t->ch[0], 0);
      }
      t = rotate(t, 1);
    } else if (depthL - depthR == -2) {
      if (depth(t->ch[1]->ch[0]) > depth(t->ch[1]->ch[1])) {
        t->ch[1] = rotate(t->ch[1], 1);
      }
      t = rotate(t, 0);
    }
    return t;
  }
  static node *insert(node *t, int k, T v) {
    if (!t)
      return new node(v);
    int countL = count(t->ch[0]);
    if (k <= countL)
      t->ch[0] = insert(t->ch[0], k, v);
    else
      t->ch[1] = insert(t->ch[1], k - (countL + 1), v);
    return fix(update(t));
  }
  static node *erase(node *t) {
    if (!t)
      return t;
    if (!t->ch[0] && !t->ch[1])
      return nullptr;
    if (!t->ch[0] || !t->ch[1])
      return t->ch[t->ch[0] == nullptr];
    return fix(
        update(new node(find(t->ch[1], 0)->val, t->ch[0], erase(t->ch[1], 0))));
  }
  static node *erase(node *t, int k) {
    if (!t)
      return t;
    int countL = count(t->ch[0]);
    if (k < countL) {
      t->ch[0] = erase(t->ch[0], k);
      update(t);
    } else if (k > countL) {
      t->ch[1] = erase(t->ch[1], k - (countL + 1));
      update(t);
    } else {
      t = erase(t);
    }
    return fix(t);
  }
  static node *find(node *t, int k) {
    if (!t)
      return t;
    int countL = count(t->ch[0]);
    return k < countL ? find(t->ch[0], k) : k == countL ? t : find(t->ch[1], k - (countL + 1));
  }
  static T find(node *t, int l, int r) {
    if (!t || r <= 0 || t->size <= l)
      return RMQ::id();
    if (l <= 0 && t->size <= r)
      return t->all;
    int countL = count(t->ch[0]);
    return RMQ::op(find(t->ch[0], l, r),
                 RMQ::op((l <= countL && countL < r ? t->val : RMQ::id()),
                       find(t->ch[1], l - (countL + 1), r - (countL + 1))));
  }
  node *root;

public:
  avl_tree() : root(nullptr) {}
  int size() const { return count(root); }
  void insert(int k, T b) { root = insert(root, k, b); }
  void erase(int k) { root = erase(root, k); }
  T find(int k) { return find(root, k)->val; }
  T find(int l, int r) { return find(root, l, r); }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, q;
  std::scanf("%d%d", &n, &q);
  avl_tree tree;
  for (int i = 0; i < n; i++) {
    int a;
    std::scanf("%d", &a);
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    std::scanf("%d%d%d", &x, &y, &z);
    if (x == 0) {
      int val = tree.find(z);
      tree.erase(z);
      tree.insert(y, val);
    } else if (x == 1) {
      std::printf("%d\n", tree.find(y, z + 1));
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
  return 0;
}