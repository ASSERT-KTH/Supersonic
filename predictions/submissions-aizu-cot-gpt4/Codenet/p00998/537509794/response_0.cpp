#include <bits/stdc++.h>
using namespace std;
struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return min(l, r); }
};

template <typename M> class avl_tree {
  // ... rest of the code is same ...

  node *erase(node *t) {
    if (!t)
      return t;
    if (!t->ch[0] && !t->ch[1])
      return nullptr;
    if (!t->ch[0] || !t->ch[1])
      return t->ch[t->ch[0] == nullptr];
    node *s = find(t->ch[1], 0);
    swap(t->val, s->val);
    t->ch[1] = erase(t->ch[1], 0);
    return fix(update(t));
  }

  // ... rest of the code is same ...

  node *find(node *t, int k) const {
    if (!t || k < 0 || k >= t->size)
      return nullptr;
    int c = count(t->ch[0]);
    return k < c ? find(t->ch[0], k) : k == c ? t : find(t->ch[1], k - (c + 1));
  }

  T find(node *t, int l, int r) const {
    if (!t || r <= 0 || l >= t->size)
      return M::id();
    if (l < 0)
      l = 0;
    if (r > t->size)
      r = t->size;
    if (l == 0 && r == t->size)
      return t->all;
    int c = count(t->ch[0]);
    return M::op(find(t->ch[0], l, r),
                 M::op((l <= c && c < r ? t->val : M::id()),
                       find(t->ch[1], l - (c + 1), r - (c + 1))));
  }

  // ... rest of the code is same ...
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
      cout << tree.find(y, z + 1) << '\n';
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
  return 0;
}