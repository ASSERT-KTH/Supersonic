#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return min(l, r); }
};

template <typename M>
class avl_tree {
  //... same as before ...
  node *erase(node *t) {
    if (!t)
      return t;
    if (!t->ch[0] && !t->ch[1]) {
      delete t;
      return nullptr;
    }
    if (!t->ch[0] || !t->ch[1]) {
      node* temp = t->ch[t->ch[0] == nullptr];
      delete t;
      return temp;
    }
    //.. same as before ..
  }
  //.. same as before ..
};

int main() {
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