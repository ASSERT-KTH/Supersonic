#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

const int INF = 1 << 30;

struct Treap {
  struct Node {
    int value;
    int priority;
    int cnt;
    int small;
    std::vector<Node*> children;

    Node(int v) : value(v), priority(rand()), cnt(1), small(v) {}
  };

  Node* root;

  Treap() : root(nullptr) {}

  int count(Node* t) { return t ? t->cnt : 0; }

  int mini(Node* t) { return t ? t->small : INF; }

  void update(Node* t) {
    t->cnt = count(t->children[0]) + count(t->children[1]) + 1;
    t->small = std::min(std::min(mini(t->children[0]), mini(t->children[1])), t->value);
  }

  Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;

    if (l->priority > r->priority) {
      l->children[1] = merge(l->children[1], r);
      update(l);
      return l;
    } else {
      r->children[0] = merge(l, r->children[0]);
      update(r);
      return r;
    }
  }

  std::pair<Node*, Node*> split(Node* t, int k) {
    if (!t) return { nullptr, nullptr };

    if (k <= count(t->children[0])) {
      auto [left, right] = split(t->children[0], k);
      t->children[0] = right;
      update(t);
      return { left, t };
    } else {
      auto [left, right] = split(t->children[1], k - count(t->children[0]) - 1);
      t->children[1] = left;
      update(t);
      return { t, right };
    }
  }

  Node* insert(Node* t, int k, int val) {
    auto [left, right] = split(t, k);
    Node* newNode = new Node(val);
    t = merge(merge(left, newNode), right);
    return t;
  }

  Node* erase(Node* t, int k) {
    auto [left, right] = split(t, k + 1);
    auto [mid, _] = split(left, k);
    t = merge(mid, right);
    return t;
  }

  Node* find(Node* t, int k) {
    while (t) {
      int c = count(t->children[0]);

      if (k < c) {
        t = t->children[0];
      } else if (k > c) {
        t = t->children[1];
        k -= c + 1;
      } else {
        return t;
      }
    }

    return nullptr;
  }

  int rmq(Node* t, int l, int r) {
    if (!t || l >= count(t) || r <= 0) return INF;

    if (l <= 0 && r >= count(t)) return mini(t);

    int ret = std::min(rmq(t->children[0], l, r), rmq(t->children[1], l - count(t->children[0]) - 1, r - count(t->children[0]) - 1));

    if (l <= count(t->children[0]) && count(t->children[0]) < r) ret = std::min(ret, t->value);

    return ret;
  }

  void insert(int k, int v) { root = insert(root, k, v); }

  void erase(int k) { root = erase(root, k); }

  Node* find(int k) { return find(root, k); }

  int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  Treap tree;

  std::cin >> n >> q;

  for (int i = 0, a; i < n; i++) {
    std::cin >> a;
    tree.insert(i, a);
  }

  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;

    if (x == 0) {
      z++;
      auto [a, b] = tree.split(tree.root, z);
      auto [c, d] = tree.split(a, z - 1);
      tree.root = tree.merge(tree.merge(d, c), b);
    } else if (x == 1) {
      std::cout << tree.rmq(y, z + 1) << "\n";
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}