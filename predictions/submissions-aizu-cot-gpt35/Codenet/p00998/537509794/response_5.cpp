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
  node *rotate(node *t, int b) {
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
      if (depth(t->ch[0]->ch[1]) > depth(t->ch[0]->ch[0])) {
        t->ch[0] = rotate(t->ch[0], 0);
      }
      t = rotate(t, 1);
    } else if (depth(t->ch[0]) - depth(t->ch[1]) == -2) {
      if (depth(t->ch[1]->ch[0]) > depth(t->ch[1]->ch[1])) {
        t->ch[1] = rotate(t->ch[1], 1);
      }
      t = rotate(t, 0);
    }
    return t;
  }
  node *insert(node *t, int k, T v) {
    if (!t)
      return new node(v);
    int c = count(t->ch[0]);
    if (k <= c)
      t->ch[0] = insert(t->ch[0], k, v);
    else
      t->ch[1] = insert(t->ch[1], k - (c + 1), v);
    return fix(update(t));
  }
  node *erase(node *t) {
    if (!t)
      return t;
    if (!t->ch[0] && !t->ch[1])
      return nullptr;
    if (!t->ch[0] || !t->ch[1])
      return t->ch[t->ch[0] == nullptr];
    return fix(
        update(new node(find(t->ch[1], 0)->val, t->ch[0], erase(t->ch[1], 0))));
  }
  node *erase(node *t, int k) {
    if (!t)
      return t;
    int c = count(t->ch[0]);
    if (k < c) {
      t->ch[0] = erase(t->ch[0], k);
      update(t);
    } else if (k > c) {
      t->ch[1] = erase(t->ch[1], k - (c + 1));
      update(t);
    } else {
      t = erase(t);
    }
    return fix(t);
  }
  node *find(node *t, int k) const {
    if (!t)
      return t;
    int c = count(t->ch[0]);
    return k < c ? find(t->ch[0], k) : k == c ? t : find(t->ch[1], k - (c + 1));
  }
  T find(node *t, int l, int r) const {
    if (!t || r <= 0 || t->size <= l)
      return M::id();
    if (l <= 0 && t->size <= r)
      return t->all;
    int c = count(t->ch[0]);
    return M::op(find(t->ch[0], l, r),
                 M::op((l <= c && c < r ? t->val : M::id()),
                       find(t->ch[1], l - (c + 1), r - (c + 1))));
  }
  node *root;

public:
  avl_tree() : root(nullptr) {}
  int size() const { return count(root); }
  void insert(int k, T b) { root = insert(root, k, b); }
  void erase(int k) { root = erase(root, k); }
  T find(int k) const { return find(root, k)->val; }
  T find(int l, int r) const { return find(root, l, r); }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  avl_tree<RMQ> tree;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0) {
      int val = tree.find(z);
      tree.erase(z);
      tree.insert(y, val);
    } else if (x == 1) {
      cout << tree.find(y, z + 1) << "\n";
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
  return 0;
}