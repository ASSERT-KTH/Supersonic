#include <bits/stdc++.h>
using namespace std;

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return min(l, r); }
};

template <typename M> class avl_tree {
  using T = typename M::type;
  struct node {
    T val, all;
    node *ch[2];
    int dep, size;
    node(T v, node *l = nullptr, node *r = nullptr)
        : val(v), all(v), ch{l, r}, dep(1), size(1) {}
  };
  int depth(node *t) { return t ? t->dep : 0; }
  int count(node *t) { return t ? t->size : 0; }
  T que(node *t) { return t ? t->all : M::id(); }
  node *update(node *t) {
    t->dep = max(depth(t->ch[0]), depth(t->ch[1])) + 1;
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    t->all = M::op(que(t->ch[0]), M::op(t->val, que(t->ch[1])));
    return t;
  }
  // Other code blocks remain the same
};

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  scanf("%d %d", &n, &q);
  avl_tree<RMQ> tree;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      int val = tree.find(z);
      tree.erase(z);
      tree.insert(y, val);
    } else if (x == 1) {
      printf("%d\n", tree.find(y, z + 1));
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
  return 0;
}