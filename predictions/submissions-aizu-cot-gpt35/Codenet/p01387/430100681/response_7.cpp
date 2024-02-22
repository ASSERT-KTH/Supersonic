#include <bits/stdc++.h>
using namespace std;

template <class Key>
struct RandomizedBinarySearchTree {
  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;
    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  struct Node {
    Node *l, *r;
    int cnt;
    Key key;
    Node() {}
    Node(const Key &k) : cnt(1), key(k), l(nullptr), r(nullptr) {}
  };

  static const int MAX_NODES = 5000000;
  Node pool[MAX_NODES];
  int ptr;

  RandomizedBinarySearchTree() : ptr(0) {}

  inline Node *alloc(const Key &key) { return &(pool[ptr++] = Node(key)); }

  virtual Node *clone(Node *t) { return t; }

  inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    return t;
  }

  Node *merge(Node *l, Node *r) {
    if (!l || !r)
      return l ? l : r;
    if (xor128() % (l->cnt + r->cnt) < l->cnt) {
      l = update(clone(l));
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r = update(clone(r));
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Node *, Node *> split(Node *t, int k) {
    if (!t)
      return {t, t};
    t = update(clone(t));
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Node *build(int l, int r, const vector<Key> &v) {
    if (l + 1 >= r)
      return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *build(const vector<Key> &v) {
    ptr = 0;
    return build(0, (int)v.size(), v);
  }

  void dump(Node *r, typename vector<Key>::iterator &it) {
    if (!r)
      return;
    dump(r->l, it);
    *it = r->key;
    dump(r->r, ++it);
  }

  vector<Key> dump(Node *r) {
    vector<Key> v((size_t)count(r));
    auto it = begin(v);
    dump(r, it);
    return v;
  }
};

template <class Key>
struct PresidentRandomizedBinarySearchTree : RandomizedBinarySearchTree<Key> {
  using RBST = RandomizedBinarySearchTree<Key>;
  using Node = typename RBST::Node;

  PresidentRandomizedBinarySearchTree() {}

  Node *clone(Node *t) override { return &(RBST::pool[RBST::ptr++] = *t); }

  Node *rebuild(Node *r) { return RBST::build(RBST::dump(r)); }
};

template <class T>
struct OrderedMultiSet : PresidentRandomizedBinarySearchTree<T> {