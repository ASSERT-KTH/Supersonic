#include <algorithm>
#include <cstdio>
#include <climits>

struct RMQ {
  using type = int;
  static inline type id() { return INT_MAX; }
  static inline type op(type l, type r) { return std::min(l, r); }
};

template <typename M> class avl_tree {
  // ... rest of the avl_tree class ...

public:
  avl_tree() : root(nullptr) {}
  inline int size() const { return count(root); }
  void insert(int k, M::type b) { root = insert(root, k, b); }
  void erase(int k) { root = erase(root, k); }
  M::type find(int k) const { return find(root, k)->val; }
  M::type find(int l, int r) const { return find(root, l, r); }
};

int main() {
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