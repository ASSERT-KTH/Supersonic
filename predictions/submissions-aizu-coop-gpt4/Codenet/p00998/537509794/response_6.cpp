#include <iostream>
#include <algorithm>
#include <climits>
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
    int depth_l = depth(t->ch[0]);
    int depth_r = depth(t->ch[1]);
    t->dep = max(depth_l, depth_r) + 1;

    int count_l = count(t->ch[0]);
    int count_r = count(t->ch[1]);
    t->size = count_l + 1 + count_r;

    T que_l = que(t->ch[0]);
    T que_r = que(t->ch[1]);
    t->all = M::op(que_l, M::op(t->val, que_r));

    return t;
  }

  // rest of the code remains same
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