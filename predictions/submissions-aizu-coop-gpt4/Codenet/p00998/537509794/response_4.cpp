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
    shared_ptr<node> ch[2];
    int dep, size;
    node(T v, shared_ptr<node> l = nullptr, shared_ptr<node> r = nullptr)
        : val(v), all(v), ch{l, r}, dep(1), size(1) {}
  };
  shared_ptr<node> root;

  // ... Rest of the code is similar ...

public:
  avl_tree() : root(nullptr) {}
  int size() const { return count(root); }
  void insert(int k, T b) { root = insert(root, k, b); }
  void erase(int k) { root = erase(root, k); }
  T find(int k) const { return find(root, k)->val; }
  T find(int l, int r) const { return find(root, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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