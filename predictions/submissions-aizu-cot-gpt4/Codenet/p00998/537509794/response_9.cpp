#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return min(l, r); }
};

//... rest of the code remains unchanged ...

int main() {
  ios::sync_with_stdio(true), cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  avl_tree<RMQ> tree;
  for (int i = 0; i < n; ++i) {
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