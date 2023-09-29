#include <bits/stdc++.h>
using namespace std;
template <class Key> struct RandomizedBinarySearchTree {
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
  vector<Node> pool;
  int ptr;
  RandomizedBinarySearchTree(int sz) : pool(sz), ptr(0) {}
  inline Node *alloc(const Key &key) { return &(pool[ptr++] = Node(key)); }
  virtual Node *clone(Node *t) { return t; }
  inline int count(const Node *t) { return t ? t->cnt : 0; }
  inline Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    return t;
  }
  inline Node *propagete(Node *t) { return update(clone(t)); }
  Node *merge(Node *l, Node *r) {
    if (!l || !r)
      return l ? l : r;
    if (xor128() % (l->cnt + r->cnt) < l->cnt) {
      l = propagete(l);
      l->r = merge(l->r, r);
  