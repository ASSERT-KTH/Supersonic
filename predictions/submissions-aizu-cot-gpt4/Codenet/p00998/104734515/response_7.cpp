#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int INF = 1 << 30;

struct Treap {
  // Rest of the code is same until main function

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

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
      z++;
      pair<Treap::node *, Treap::node *> a, b, c;
      c = tree.split(tree.root, z);
      b = tree.split(c.first, z - 1);
      a = tree.split(b.first, y);
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << '\n';
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}