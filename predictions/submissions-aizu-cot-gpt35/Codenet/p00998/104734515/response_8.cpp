#include <iostream>
#include <random>
#include <stack>

const int INF = 1 << 30;

struct Treap {
  struct node {
    int value;
    node* left;
    node* right;
    int priority;
    int cnt;
    int small;
    node(int v)
        : value(v),
          left(nullptr),
          right(nullptr),
          priority(0),
          cnt(1),
          small(v) {}
  };

  node* root;
  std::random_device rd;
  std::mt19937 gen;

  Treap() : root(nullptr), gen(rd()) {}

  int count(node* t) { return t ? t->cnt : 0; }
  int mini(node* t) { return t ? t->small : INF; }

  node* update(node* t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = std::min(std::min(mini(t->left), mini(t->right)), t->value);
    return t;
  }

  node* merge(node* l, node* r) {
    if (!l || !r) return l ? l : r;
    if (l->priority > r->priority) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  std::pair<node*, node*> split(node* t, int k) {
    if (!t) return {nullptr, nullptr};

    std::pair<node*, node*> result = {nullptr, nullptr};
    node* curr = t;

    while (curr) {
      if (k <= count(curr->left)) {
        result.second = curr;
        curr = curr->left;
      } else {
        result.first = curr;
        k -= count(curr->left) + 1;
        curr = curr->right;
      }
    }

    if (result.second) result.second->left = nullptr;
    if (result.first) result.first->right = nullptr;

    return result;
  }

  node* insert(node* t, int k, int val) {
    std::pair<node*, node*> s = split(t, k);
    t = merge(s.first, new node(val));
    return update(merge(t, s.second));
  }

  node* erase(node* t, int k) {
    std::pair<node*, node*> s1, s2;
    s1 = split(t, k + 1);
    s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    return update(t);
  }

  node* find(node* t, int k) {
    int c = count(t->left);
    if (k < c)
      return find(t->left, k);
    else if (k > c)
      return find(t->right, k - c - 1);
    else
      return t;
  }

  int rmq(node* t, int l, int r) {
    if (l >= count(t) || r <= 0) return INF;
    if (l <= 0 && r >= count(t)) return mini(t);

    std::stack<node*> stk;
    stk.push(t);
    int ret = INF;

    while (!stk.empty()) {
      node* curr = stk.top();
      stk.pop();

      int size = count(curr->left);
      ret = std::min(ret, rmq(curr->left, l, r));
      ret = std::min(ret, rmq(curr->right, l - size - 1, r - size - 1));

      if (l <= size && size < r) ret = std::min(ret, curr->value);

      if (curr->right) stk.push(curr->right);
      if (curr->left) stk.push(curr->left);
    }

    return ret;
  }

  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  node* find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};

int main() {
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
      std::pair<Treap::node*, Treap::node*> a, b, c;
      c = tree.split(tree.root, z);
      b = tree.split(c.first, z - 1);
      a = tree.split(b.first, y);
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      std::cout << tree.rmq(y, z + 1) << std::endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }

  return 0;
}