#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand() ^ (rand() << 16)), cnt(1), small(v) {
      left = right = NULL;
    }
  };
  node *root;
  Treap() : root(NULL) {}
  inline int count(node *t) { return !t ? 0 : t->cnt; }
  inline int mini(node *t) { return !t ? INF : t->small; }
  node *update(node *t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
    return t;
  }
  // rest of the code remains same
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
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
      // rest of the code remains same
    } else if (x == 1) {
      printf("%d\n", tree.rmq(y, z + 1));
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}