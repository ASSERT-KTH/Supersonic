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
  int depth(node *t) const { return t ? t->dep : 0; }
  int count(node *t) const { return t ? t->size : 0; }
  T que(node *t) const { return t ? t->all : M::id(); }
  node *update(node *t) {
    t->dep = max(depth(t->ch[0]), depth(t->ch[1])) + 1;
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    t->all = M::op(que(t->ch[0]), M::op(t->val, que(t->ch[1])));
    return t;
  }
  node *rotate(const node *t, int b) {
    node *s = t->ch[1 - b];
    t->ch[1 - b] = s->ch[b];
    s->ch[b] = t;
    update(t);
    return update(s);
  }
  node *fix(node *t) {
    if (!t)
      return t;
    if (depth(t->ch[0]) - depth(t->ch[1]) == 2) {
      if (depth(