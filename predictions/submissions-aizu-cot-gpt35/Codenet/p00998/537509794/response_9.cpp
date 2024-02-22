#include <iostream>
#include <vector>
#include <algorithm>

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return std::min(l, r); }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<RMQ::type> tree(n);
  for (int i = 0; i < n; i++) {
    std::cin >> tree[i];
  }

  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;

    if (x == 0) {
      int val = tree[z];
      tree.erase(tree.begin() + z);
      tree.insert(tree.begin() + y, val);
    } else if (x == 1) {
      std::cout << *std::min_element(tree.begin() + y, tree.begin() + z + 1) << "\n";
    } else {
      tree[y] = z;
    }
  }

  return 0;
}