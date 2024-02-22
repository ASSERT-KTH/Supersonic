#include <iostream>
#include <cstdio>
#include <random>
const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand()), cnt(1), small(v) {
      left = right = nullptr;
    }
  };
  node *root;
  std::mt19937 rng;
  
  Treap() : root(nullptr), rng(std::random_device()()) {}
  
  int count(node *t) { return t ? t->cnt : 0; }
  int mini(node *t) { return t ? t->small : INF; }
  
  void update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = std::min(std::min(mini(t->left), mini(t->right)), t->value);
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
  
  std::pair<node *, node *> split(node *t, int k) {
    if (!t)
      return {nullptr, nullptr};
    if (k <= count(t->left)) {
      auto s = split(t->left, k);
      t->left = s.second;
      update(t);
      return {s.first, t};
    } else {
      auto s = split(t->right, k - count(t->left) - 1);
      t->right = s.first;
      update(t);
      return {t, s.second};
    }
  }
  
  node *insert(node *t, int k, int val) {
    auto s = split(t, k);
    t = merge(s.first, new node(val));
    t = merge(t, s.second);
    return t;
  }
  
  node *erase(node *t, int k) {
    auto s1 = split(t, k + 1);
    auto s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    return t;
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
    if (l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);
    
    int ret = INF;
    int size = count(t->left);
    
    if (l <= size && size < r)
      ret = std::min(ret, t->value);
    
    if (l < size)
      ret = std::min(ret, rmq(t->left, l, r));
    if (r > size + 1)
      ret = std::min(ret, rmq(t->right, l - size - 1, r - size - 1));
    
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
  std::scanf("%d %d", &n, &q);
  
  for (int i = 0, a; i < n; i++) {
    std::scanf("%d", &a);
    tree.insert(i, a);
  }
  
  while (q--) {
    int x, y, z;
    std::scanf("%d %d %d", &x, &y, &z);
    
    if (x == 0) {
      z++;
      auto c = tree.split(tree.root, z);
      auto b = tree.split(c.first, z - 1);
      auto a = tree.split(b.first, y);
      
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      std::cout << tree.rmq(y, z + 1) << '\n';
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}