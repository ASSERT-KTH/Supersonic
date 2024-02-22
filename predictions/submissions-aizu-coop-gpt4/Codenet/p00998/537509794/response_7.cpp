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
  // [omitted for brevity, no changes made to this part]
};

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
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