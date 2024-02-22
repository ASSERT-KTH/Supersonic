#include <iostream>
#include <climits>

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(type l, type r) { return std::min(l, r); }
};

template <typename M>
class avl_tree {
  using T = typename M::type;

  struct node {
    T val;
    node* ch[2];
    int dep, size;

    node(T v, node* l = nullptr, node* r = nullptr)
        : val(v), ch{l, r}, dep(1), size(1) {}
  };

  int depth(node* t) const { return t ? t->dep : 0; }

  node* rotate(node* t, int b) {
    node* s = t->ch[1 - b];
    t->ch[1 - b] = s->ch[b];
    s->ch[b] = t;
    t->dep = std::max(depth(t->ch[0]), depth(t->ch[1])) + 1;
    s->dep = std::max(depth(s->ch[0]), depth(s->ch[1])) + 1;
    return s;
  }

  node* fix(node* t) {
    if (!t)
      return t;
    if (depth(t->ch[0]) - depth(t->ch[1]) == 2) {
      if (depth(t->ch[0]->ch[1]) > depth(t->ch[0]->ch[0])) {
        t->ch[0] = rotate(t->ch[0], 0);
      }
      t = rotate(t, 1);
    } else if (depth(t->ch[0]) - depth(t->ch[1]) == -2) {
      if (depth(t->ch[1]->ch[0]) > depth(t->ch[1]->ch[1])) {
        t->ch[1] = rotate(t->ch[1], 1);
      }
      t = rotate(t, 0);
    }
    return t;
  }

  node* insert(node* t, int k, T v) {
    if (!t)
      return new node(v);
    if (k <= count(t->ch[0]))
      t->ch[0] = insert(t->ch[0], k, v);
    else
      t->ch[1] = insert(t->ch[1], k - count(t->ch[0]) - 1, v);
    t->dep = std::max(depth(t->ch[0]), depth(t->ch[1])) + 1;
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    return fix(t);
  }

  node* erase(node* t, int k) {
    if (!t)
      return t;
    if (k < count(t->ch[0])) {
      t->ch[0] = erase(t->ch[0], k);
    } else if (k > count(t->ch[0])) {
      t->ch[1] = erase(t->ch[1], k - count(t->ch[0]) - 1);
    } else {
      if (!t->ch[0] && !t->ch[1])
        return nullptr;
      if (!t->ch[0] || !t->ch[1])
        return t->ch[t->ch[0] == nullptr];
      node* min_node = find(t->ch[1], 0);
      t->val = min_node->val;
      t->ch[1] = erase(t->ch[1], 0);
    }
    t->dep = std::max(depth(t->ch[0]), depth(t->ch[1])) + 1;
    t->size = count(t->ch[0]) + 1 + count(t->ch[1]);
    return fix(t);
  }

  node* find(node* t, int k) const {
    if (!t)
      return t;
    int curr_index = count(t->ch[0]);
    while (curr_index != k) {
      if (k < curr_index) {
        t = t->ch[0];
      } else {
        t = t->ch[1];
        k -= (curr_index + 1);
      }
      curr_index = count(t->ch[0]);
    }
    return t;
  }

  node* root;

public:
  avl_tree() : root(nullptr) {}

  int size() const { return count(root); }

  void insert(int k, T b) { root = insert(root, k, b); }

  void erase(int k) { root = erase(root, k); }

  T find(int k) const { return find(root, k)->val; }

  T find(int l, int r) const { return M::op(find(root, l)->val, find(root, r + 1)->val); }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  avl_tree<RMQ> tree;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    tree.insert(i, a);
  }

  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x == 0) {
      int val = tree.find(z);
      tree.erase(z);
      tree.insert(y, val);
    } else if (x == 1) {
      std::cout << tree.find(y, z) << "\n";
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}