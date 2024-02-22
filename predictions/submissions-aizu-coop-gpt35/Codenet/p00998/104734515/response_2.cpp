#include <iostream>
#include <cstdlib>
using namespace std;

const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand()), cnt(1), small(v), left(nullptr), right(nullptr) {}
    int getCount() { return cnt; }
    int getMin() { return small; }
    void update() {
      cnt = getCount(left) + getCount(right) + 1;
      small = min(min(mini(left), mini(right)), value);
    }
  };

  node *root;

  Treap() : root(nullptr) {}

  int getCount(node *t) { return t ? t->getCount() : 0; }
  int getMin(node *t) { return t ? t->getMin() : INF; }

  node *merge(node *l, node *r) {
    if (!l || !r)
      return l ? l : r;
    if (l->priority > r->priority) {
      l->right = merge(l->right, r);
      l->update();
      return l;
    } else {
      r->left = merge(l, r->left);
      r->update();
      return r;
    }
  }

  pair<node *, node *> split(node *t, int k) {
    if (!t)
      return make_pair(nullptr, nullptr);
    if (k <= getCount(t->left)) {
      pair<node *, node *> s = split(t->left, k);
      t->left = s.second;
      t->update();
      return make_pair(s.first, t);
    } else {
      pair<node *, node *> s = split(t->right, k - getCount(t->left) - 1);
      t->right = s.first;
      t->update();
      return make_pair(t, s.second);
    }
  }

  node *insert(node *t, int k, int val) {
    pair<node *, node *> s = split(t, k);
    t = merge(s.first, new node(val));
    return merge(t, s.second);
  }

  node *erase(node *t, int k) {
    pair<node *, node *> s1, s2;
    s1 = split(t, k + 1);
    s2 = split(s1.first, k);
    return merge(s2.first, s1.second);
  }

  node *find(node *t, int k) {
    while (t) {
      int c = getCount(t->left);
      if (k < c)
        t = t->left;
      else if (k > c)
        t = t->right, k -= c + 1;
      else
        return t;
    }
    return nullptr;
  }

  int rmq(node *t, int l, int r) {
    while (t) {
      int size = getCount(t->left);
      if (l >= getCount(t) || r <= 0)
        return INF;
      if (l <= 0 && r >= getCount(t))
        return getMin(t);
      int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
      if (l <= size && size < r)
        ret = min(ret, t->value);
      return ret;
    }
    return INF;
  }

  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  node *find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
  int n, q;
  Treap tree;
  cin >> n >> q;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0) {
      z++;
      pair<Treap::node *, Treap::node *> a, b, c;
      c = tree.split(tree.root, z);
      b = tree.split(c.first, z - 1);
      a = tree.split(b.first, y);
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
  return 0;
}